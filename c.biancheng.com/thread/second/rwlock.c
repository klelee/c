#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int x = 0;    // 定义一个多线程共享变量

pthread_rwlock_t my_rwlock;

void * read_thread(void * args) {
    printf("%u read_thread readly\n", pthread_self());
    while(1) {
        sleep(1);
        pthread_rwlock_rdlock(&my_rwlock);
        printf("read_thread %u get rdlock! x = %d \n", pthread_self(), x);
        sleep(1);
        pthread_rwlock_unlock(&my_rwlock);
    }
    return NULL;
}

void * write_thread(void * args) {
    printf("%u write_thread readly\n", pthread_self());
    while(1) {
        sleep(1);
        pthread_rwlock_wrlock(&my_rwlock);
        x++;
        printf("write_thread %u get wrlock! x = %d \n", pthread_self, x);
        sleep(1);
        pthread_rwlock_unlock(&my_rwlock);
    } 
    return 0;
}

int main() {
    int i;

    pthread_rwlock_init(&my_rwlock, NULL);
    pthread_t read_threads[3];

    for (i = 0; i < 3; i++) {
        pthread_create(&read_threads[i], NULL, read_thread, NULL);
    }

    pthread_t write_threads;
    pthread_create(&write_threads, NULL, write_thread, NULL);
    
    pthread_join(write_threads, NULL);
    for (i = 0; i < 3; i++) {
        pthread_join(read_threads[i], NULL);
    }

    pthread_rwlock_destroy(&my_rwlock);
    return 0;
}