/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-10 00:17:47
 */
#include <iostream>
#include <vector>
#include <string>
#include<cmath>

using namespace std;

bool isUgly(int n){
    long n=(long)n;
    if(n==1||n==2)return true;
    if(n<=0)return false;
    while(n>=2){
        if((n+2)%2==0){
            n/=2;
            continue;
        }
        if((n+3)%3==0){
            n/=3;
            continue;
        }
        if((n+5)%5==0){
            n/=5;
            continue;
        }
        return false;
    }
    return true;
}

int main(void){
    cout<<isUgly(9);
}

