#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t mySem;
int ticket_sum = 10;

void * sell_ticket (void * args) {
    printf("thread is %u now!\n", pthread_self());
    int i;
    int flag;
    for(i = 0; i < 10; i++) {
        // 当信号量大于0 时，sem_wait会对信号量做减一操作
        flag = sem_wait(&mySem);
        if (flag == 0) {
            if (ticket_sum > 0) {
                printf("Thread id %u sell ticket %d \n", pthread_self(), 10 - ticket_sum + 1);
                ticket_sum--;
            }
        }
        sem_post(&mySem);
        sleep(1);
    }
    return 0;
}

int main() {
    int i;
    int flag;
    void * ans;
    pthread_t tids[4];

    flag = sem_init(&mySem, 0, 1);
    if(flag != 0) {
        printf("sem init failed!\n");
        return 0;
    }

    for (i = 0; i < 4; i++) {
        flag = pthread_create(&tids[i], NULL, &sell_ticket, NULL);
        if (flag != 0) {
            printf("new thread failed!\n");
            return 0;
        }
    }
    sleep(10);
    for (i = 0; i < 4; i++) {
        flag = pthread_join(tids[i], &ans);
        if (flag != 0) {
            printf("wait for thread %u failed!\n", pthread_self());
            return 0;
        }
    }
    sem_destroy(&mySem);
    return 0;
}