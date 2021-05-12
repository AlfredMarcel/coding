/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-22 21:36:16
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
int q[100010];
int tmp[100010];

void mergesort(int* q,int l,int r){
    if(l>=r)return;
    int mid=(l+r)>>1;
    mergesort(q,l,mid);
    mergesort(q,mid+1,r);

    int k=0;
    int i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(q[i]<q[j])tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];
    for(i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)cin>>q[i];
    mergesort(q,0,n-1);
    for(int i=0;i<n;i++)cout<<q[i]<<" ";
}
