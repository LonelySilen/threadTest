#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h> 
/*
 *gcc -o multi_thread_read_write_demo multi_thread_read_write_demo.c –lpthread
 */
sem_t read_ok;
sem_t write_ok;

void write()
{
        while(1)
        {
                sem_wait(&read_ok);
                printf("\t\t\t\twriting\n");
                sleep(10);
                printf("\n\t\t\t\t\t<== notify main thread start exporting!\n");
                sem_post(&write_ok);
        }
}

int main()
{
        time_t time1=time(NULL);
        printf("/***MULTI THREAD DEMO!***/\n");
        pthread_t thread_write;
        sem_init(&read_ok,0,0);
        sem_init(&write_ok,0,1);
        pthread_create(&thread_write,NULL,(void *) write,NULL);
        int i=0;
        for(i=0;i<3;i++)
        {
                printf("\t\t\treading!\n");
                sleep(2);
                printf("\testablishing data structure!\n");
                sleep(2);
                sem_wait(&write_ok);
                printf("\texporting data to array!\n");
                sleep(2);
                printf("\nnotify writing thread start working ==>\n");
                sem_post(&read_ok);
                printf("\tdestorying data structure!\n");
                sleep(2);
        }
        sem_wait(&write_ok);
        time_t time2=time(NULL);
        printf("-------*^v^*-------well done,time spent %d seconds-------*^v^*-------\n",(int)(time2-time1));

        time1=time(NULL);
        printf("\n\n/*** SINGLE THREAD DEMO ***/\n");
        for(i=0;i<3;i++)
        {
                printf("\t\t\treading\n");
                sleep(2);
                printf("\testablishing data structure!\n");
                sleep(2);
                printf("\texporing data to array!\n");
                sleep(2);
                printf("\t\t\t\twriting\n");
                sleep(10);
                printf("\tdestorying data structure!\n");
                sleep(2);
        }
        time2=time(NULL);
        printf("-------*^v^*-------well done,time spent %d seconds-------*^v^*-------\n",(int)(time2-time1));
}

