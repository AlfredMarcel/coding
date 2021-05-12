/*
 * @Description: 
 * @Author: Marcel
 * @Date: 2021-05-07 22:17:32
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,q,k;
int seq[100010];

int search_left(int l,int r){
    while (l<r){
        int mid=l+r>>1;
        if(seq[mid]>=k)r=mid;
        else l=mid+1;
    }
    if(seq[l]==k)return l;
    return -1;
}

int search_right(int l,int r){
    while(l<r){
        int mid=l+r+1>>1;
        if(seq[mid]<=k)l=mid;
        else r=mid-1;
    }
    if(seq[l]==k)return l;
    return -1;
}

int main(void){
    ios::sync_with_stdio("false");
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    for(int i=0;i<q;i++){
        cin>>k;
        int l=search_left(0,n-1);
        int r=search_right(0,n-1);
        cout<<l<<" "<<r<<"\n";
    }
}

