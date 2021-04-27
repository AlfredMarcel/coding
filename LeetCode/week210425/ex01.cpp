/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-25 10:27:52
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sumBase(int n, int k) {
    int sum=0;
    while(n>=k){
        sum+=n%k;
        n/=k;
    }
    sum+=n;
    return sum;
}

int main(void){
    cout<<sumBase(10,10);
}
