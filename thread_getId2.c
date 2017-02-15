#include<pthread.h>
#include<stdio.h>
void * func(void *arg)
{
	printf("the pid of the programming is %d\n",getpid());
	printf("the new thread is :%lu\n",pthread_self());
	return ((void*) 0);
}
int main()
{
	pthread_t tid=pthread_self();//tid 是main这个线程的id
	pthread_t ntid; 
	printf("the main thread is %lu:\n",tid);
	//pid_t pid=getpid();//pid 是进程的id
	int pid=_getpid();//旧的原型为pid_t getpid(void);，推荐使用int _getpid( void );这种形式
	printf("the pid of the process is %d:\n",pid);
	printf("the thread ntid now is %lu:\n",ntid);//未分配，为随机数
	int err=pthread_create(&ntid,NULL,func,NULL);
	if(err!=0)
	{
		printf("create thread error\n");
	}
	sleep(1);
	return 0;
}
