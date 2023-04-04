#include <stdio.h>
#include <pthread.h>

void *Thread1(void *arg){
	printf("klelee thread 1!\n");
	return "Thread1 success";
}

void *Thread2(void *arg){
	printf("klelee thread 2!\n");
	return "Thread2 success";
}

int main(){
	int res;
	pthread_t mythread1, mythread2;
	void* thread_result;
	/* 
	 * 创建线程：
	 * &mythread:要创建的线程
	 * NULL：不修改新建线程的任何属性
	 * ThreadFun：新建线程要执行的任务
	 * NULL：不传递给ThreadFun()函数任何参数
	 *
	 * 返回值res为0表示线程创建成功，反之则创建失败
	 */

	res = pthread_create(&mythread1, NULL, Thread1, NULL);
	if (res != 0) {
		printf("create thread failed!\n");
		return 0;
	}
	
	res = pthread_create(&mythread2, NULL, Thread2, NULL);
	if (res != 0) {
		printf("create thread failed!\n");
		return 0;
	}
	/* 
	 * 等待指定线程执行完毕
	 * myThread:指定等待的线程
	 * &thread_result:接收ThreadFun()函数的返回值，或者接收pthread_exit()函数指定的值
	 * 返回值res为0表示函数执行成功，反之则运行失败
	 */
	res = pthread_join(mythread1, &thread_result);
	printf("%s\n", (char*)thread_result);

	res = pthread_join(mythread2, &thread_result);
	printf("%s\n", (char*)thread_result);

	printf("main thread finished!\n");
	
	return 0;
}

