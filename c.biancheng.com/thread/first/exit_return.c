#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * thread_func (void * arg) {
    printf("https://klelee.com\n");
    sleep(5);
    printf("cclike.cc\n");
}

int main() {
    int res;
    int value;
    void * mess;
    pthread_t mythread;

    res = pthread_create(&mythread, NULL, thread_func, NULL);
    if (res != 0) {
        printf("new thread failed!\n");
        return 0;
    }
    sleep(2);

    res = pthread_cancel(mythread);
    if (res != 0) {
        printf("stop thread failed!\n");
        return 0;
    }

    res = pthread_join(mythread, &mess);
    if (res != 0) {
        printf("wait for thread failed!\n");
        return 0;
    }

    if (mess == PTHREAD_CANCELED) {
        printf("force stop thread sucess!\n");
    }else {
        printf("force stop thread failed!\n");
    }

    printf("main thread will return!\n");
    pthread_exit(NULL);
}