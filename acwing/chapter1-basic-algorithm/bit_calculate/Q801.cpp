/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-12 17:55:44
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
int q[100010];


/* 遍历 */
int count(int t){
    int sum=t&1;
    while(t!=0){
        sum+=(t>>1)&1;
        t=t>>1;
    }
    return sum;
}

/* lowbit */
int count2(int t){
    int sum=0;
    while(t){
        t-=t&t*-1;
        sum++;
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>q[i];
        cout<<count2(q[i])<<" ";
    }
}
