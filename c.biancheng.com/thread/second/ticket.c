#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int ticket_num = 10;

void * sell_ticket(void * arg) {
    int i;

    for (i = 0; i < 10; i++) {
        if(ticket_num > 0) {
            sleep(1);
            printf("%u sell %d ticket\n", pthread_self(), 10 - ticket_num + 1);
            ticket_num--;
        }
    }

    return 0;
}

int main() {
    int flag;
    int i;
    void * ans;
    pthread_t tids[4];
    for(i = 0; i < 4; i++) {
        flag = pthread_create(&tids[i], NULL, &sell_ticket, NULL);
        if (flag != 0) {
            printf("new thread failed!\n");
            return 0;
        }
    }
    sleep(10);
    for (i = 0; i < 4; i++){
        flag = pthread_join(tids[i], &ans);
        if(flag != 0) {
            printf("wait for thread return failed!\n");
            return 0;
        }
    }

    return 0;
}