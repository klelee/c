#include <stdio.h>
#include <pthread.h>

void * ThreadFun(void * arg){
	pthread_exit("https://klelee.com\n");
	printf("after pthread_exit\n");
}

int main(){
	int res;
	void * thread_result;
	pthread_t myThread;

	res = pthread_create(&myThread, NULL, ThreadFun, NULL);
	if (res != 0) {
		printf("create thread failed!\n");
		return 0;
	}

	res = pthread_join(myThread, &thread_result);
	if (res != 0) {
		printf("join thread failed!\n");
		return 0;
	}

	printf("%s", (char*)thread_result);
	return 0;
}
