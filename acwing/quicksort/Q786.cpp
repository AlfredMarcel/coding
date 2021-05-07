/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-07 21:02:20
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,k;
int q[100010];

void quick_sort(int *q,int left,int right){
    if(left>=right)return;
    int i=left-1;
    int j=right+1;
    int mid=(left+right)/2;
    int pirot=q[mid];
    while(i<j){
        do {i++;}while(q[i]<pirot);
        do{j--;}while(q[j]>pirot);
        if(i>=j)break;
        swap(q[i],q[j]);
    }
    quick_sort(q,left,j);
    quick_sort(q,j+1,right);
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>q[i];
    quick_sort(q,0,n-1);
    cout<<q[k-1];
}
