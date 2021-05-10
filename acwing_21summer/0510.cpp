/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-10 19:02:52
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

int m,n;
vector<int> box;

int xor_sum(int i){
    int sum=box[i];
    int count=1;
    while(count<m){
        sum^=box[i+count];
        count++;
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        box.push_back(tmp);
    }
    int mmax=0;
    int ss=n-m;
    for(int i=0;i<=ss;i++){
        mmax=max(mmax,xor_sum(i));
    }
    cout<<mmax;
}
