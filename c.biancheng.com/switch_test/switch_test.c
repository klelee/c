#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

enum wz {
    like = 1,
    klelee,
    wly,
    fairy
};

void test_func(enum wz name) {
    switch (name) {
        case like:
            printf("like!\n");
            break;
        case klelee:
            printf("klelee!\n");
            break;
        case wly:
            printf("wly!\n");
            break;
        case fairy:
            printf("fairy!\n");
            break;

        default:
            break;
    }
}

int main(int argc, char **argv) {
    test_func(like);
    return 0;
}