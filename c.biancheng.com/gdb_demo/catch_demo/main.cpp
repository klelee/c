#include <iostream>
using namespace std;
int main(){
    int num = 1;
    while(num <= 5){
        try{
            throw 100;
        }catch(int e){
            num++;
            cout << "next" << endl;
        }
    }
    cout << "over" << endl;
    return 0;
}
