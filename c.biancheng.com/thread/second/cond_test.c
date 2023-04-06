#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_cond_t myCond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
int x = 0;

void * wait_for_true (void * args) {
    int ret;

    ret = pthread_mutex_lock(&myMutex);
    if (ret != 0) {
        printf("thread %u mutex lock failed!\n", pthread_self());
        return NULL;
    }

    ret = pthread_cond_wait(&myCond, &myMutex);
    if (ret == 0) {
        printf("thread_a exec sucessful! Now x = %d \n", x);
    }
    pthread_mutex_unlock(&myMutex);
    return NULL;
}

void * do_for_cond (void * args) {
    int ret;

    while (x != 10) {
        ret = pthread_mutex_lock(&myMutex);
        if (ret == 0) {
            x++;
            printf("do_for_wait: x = %d\n", x);
            sleep(1);
            pthread_mutex_unlock(&myMutex);
        }
    }
    ret = pthread_cond_signal(&myCond);
    if (ret != 0) {
        printf("unlock cond failed!\n");
        return NULL;
    }
    return NULL;
}

int main() {
    int ret;
    pthread_t thread_a, thread_b;

    ret = pthread_create(&thread_a, NULL, wait_for_true, NULL);
    if (ret != 0) {
        printf("new thread_a failed!\n");
        return 0;
    }

    ret = pthread_create(&thread_b, NULL, do_for_cond, NULL);
    if (ret != 0) {
        printf("new thread_b failed!\n");
        return 0;
    }
    sleep(5);
    // 在这里回顾一下pthread_join的参数：int pthread_join(pthread_t thread, void ** retval);
    ret = pthread_join(thread_a, NULL);
    if (ret) {    // 如果只需要判断非零，可以直接写ret，不需要写ret != 0
        printf("wait for thread_a failed!\n");
        return 0;
    }

    ret = pthread_join(thread_b, NULL);
    if (ret) {
        printf("wait for thread_b failed!\n");
        return 0;
    }
    pthread_cond_destroy(&myCond);
    return 0;
}