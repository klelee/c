#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * thread_fun (void * arg) {
	printf("new thread function!\n");
	sleep(10);
}

int main() {
	pthread_t myThread;
	void * mess;
	int value;
	int res;

	res = pthread_create(&myThread, NULL, thread_fun, NULL);
	if (res != 0) {
		printf("create thread failed!\n");
		return 0;
	}
	sleep(1);

	res = pthread_cancel(myThread);
	if (res != 0) {
		printf("send cancel signel failed!\n");
		return 0;
	}
	res = pthread_join(myThread, &mess);
	if (res != 0) {
		printf("wait for thread failed!\n");
		return 0;
	}
	if (mess == PTHREAD_CANCELED) {
		printf("myThread is stop!\n");
	}else {
		printf("error\n");
	}
	return 0;
}
