#include <stdio.h>
#include "demo.h"

int main() {
    int a, b;

    printf("Please two number:\nNumber 1 :");
    scanf("%d", &a);
    printf("number 2 :");
    scanf("%d", &b);

    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", sub(a, b));

    return 0;
}