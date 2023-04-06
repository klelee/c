#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int ticket_sum = 10;
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

void * sell_ticket (void * args) {
    int i;
    int islock = 0;

    printf("thread id : %u\n", pthread_self());
    for (i = 0; i < 10; i++) {
        islock = pthread_mutex_lock(&myMutex);
        if(islock == 0) {  // 表示加锁成功了，可以买票了！
            if (ticket_sum >0) {
                sleep(1);
                printf("%u sell %d ticket \n", pthread_self(), 10 - ticket_sum + 1);
                ticket_sum--;
            }
            pthread_mutex_unlock(&myMutex);
        }
    }

    return 0;
    
}

int main() {
    int flag;
    int i;
    void * ans;

    pthread_t tids[4];
    for (i = 0; i < 4; i++) {
        flag = pthread_create(&tids[i], NULL, &sell_ticket, NULL);
        if (flag != 0) {
            printf("new thread %d failed!\n", i);
            return 0;
        }
    }

    sleep(10);
    for(i = 0; i < 4; i++) {
        flag = pthread_join(tids[i], &ans);
        if(flag != 0) {
            printf("wait for thread %u return failed!\n", pthread_self());
            return 0;
        }
    }

    return 0;
}