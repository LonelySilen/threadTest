#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//函数: pthread_equal(),若相等则返回非零值，否则返回0
int main()
{
	pthread_t thread_id;
	
	thread_id=pthread_self();//返回调用线程的线程id
	printf("Thread Id: %lu.\n",thread_id);

	if(pthread_equal(thread_id,pthread_self()))
	{
		printf("Equal!\n");
	}
	else
	{
		printf("Not Equal!\n");
	}
	return 0;
}
