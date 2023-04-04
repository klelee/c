#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * ThreadFun(void * arg) {
	if (arg == NULL) {
		printf("arg is NULL!\n");
	}else {
		printf("%s\n", (char*)arg);
	}

	return NULL;
}

int main() {
	int res;
	char * url = "https://klelee.com";
	pthread_t mythread1, mythread2;

	res = pthread_create(&mythread1, NULL, ThreadFun, NULL);
	if (res != 0) {
		printf("thread create failed!\n");
		return 0;
	}

	res = pthread_create(&mythread2, NULL, ThreadFun, (void*)url);
	if (res != 0) {
		printf("thread create failed!\n");
		return 0;
	}

	sleep(5);
	return 0;
}	
