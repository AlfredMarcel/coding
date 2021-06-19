/*
 * @Description: 最长上升子序列 nlogn写法
 * @Author: Marcel
 * @Date: 2021-06-19 14:51:34
 * q[i] ，存长度为i的最长上升子序列中，最大值（结尾元素）的最小值,这个序列是必然单调递增的。
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=100010;

int n;
int box[N];
int q[N];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>box[i];
    }

    int len=0;
    for(int i=1;i<=n;i++){
        int l=0,r=len;
        int mid;
        while(l<r){
            mid=l+r+1>>1;
            if(box[i]<=q[mid])r=mid-1;
            else l=mid;
        }
        len=max(len,l+1);
        q[l+1]=box[i];
    }
    cout<<len;
}

