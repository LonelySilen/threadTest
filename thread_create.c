#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thrd_func(void *arg);
pthread_t tid;
int main()
{
	//创建线程tid，且线程函数由thrd_func指向，是thrd_func的入口点，即马上执行此线程函数
	if(0!=pthread_create(&tid,NULL,thrd_func,NULL))
	{
		printf("Create Thread Error!\n");
		exit(-1);
	}
	printf("TID in pthread_create function: %lu.\n",tid);//why not pthread_self()?
	printf("Main Process: PID: %d,TID:%lu.\n",getpid(),pthread_self());
	
	sleep(1);//race
	
	return 0;
}

void *thrd_func(void *arg)
{
	//printf("I'm one new thread!\n");
	printf("New process:PID: %d,TID: %lu.\n",getpid(),pthread_self());
	printf("New process:PID: %d,TID: %lu.\n",getpid(),tid);
	
	pthread_exit(NULL);//退出线程
	//return ((void*)0);
}
