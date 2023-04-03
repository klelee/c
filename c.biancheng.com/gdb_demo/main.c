#include <stdio.h>
int print(int num){
    int ret = num * num;
    return ret;
}
int myfunc(int num){
    int i = 1;
    int sum = 0;
    while(i <= num){
        sum += print(i);
        i++;
    }
    return sum;
}
int main(){
    int num =0;
    scanf("%d", &num);
    int result = myfunc(num);
    printf("%d", result);
    return 0;
}
