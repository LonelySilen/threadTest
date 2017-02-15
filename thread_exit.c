#include<pthread.h>
#include<stdio.h>
void * func(void *arg)
{
	printf("the thread1 exit \n");
	pthread_exit((void *)1);//终止线程，返回一个指向某个对象的指针（pthread_join()函数会获得值1的地址并返回）。
}
void * func1(void *arg)
{
	printf("the thread2 exit \n");
	pthread_exit((void *)2);//终止线程,返回一个指向某个对象的指针（pthread_join()函数会获得值2的地址并返回）。
}
// 1.线程被其他的线程给取消 
//2.线程调用pthread_exit() 函数 
//3.线程从启动例程中返回，返回的是线程的退出码！
//通常用pthread_join()函数来取出线程的退出码.返回值 ： 0代表成功。 失败，返回的则是错误号
int main()
{
	int err;
	pthread_t tid1,tid2;
	void *tret;
	err=pthread_create(&tid1,NULL,func,NULL);//创建进程
	if(0!=err)
	{
		printf("can't create thread 1:\n");
	}	
	err=pthread_create(&tid2,NULL,func1,NULL);//创建进程
	if(0!=err)
	{
		printf("can't create thread 2:\n");
	}	
	err=pthread_join(tid1,&tret);//取出线程的退出码
	if(0!=err)
	{
		printf("can't join thread1\n");
	}	
	printf("thread1 exit code %d\n",(int)tret);
	err=pthread_join(tid2,&tret);//取出线程的退出码
	if(0!=err)
	{
		printf("can't join thread2\n");
	}	
	printf("thread2 exit code %d\n",(int)tret);
	return 0;
}
