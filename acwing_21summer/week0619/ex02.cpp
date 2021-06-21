/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-19 19:03:07
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long n,k;

int main(void){
    cin>>n>>k;
    int res=0;
    while(k>0){
        res++;
        if(k%2==1)break;
        else k/=2;
    }
    cout<<res;
}
