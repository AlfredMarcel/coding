/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-11 21:20:07
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,m,x;
int A[100010],B[100010];

int myfind(int target,int *box,int r){
    int l=0;
    while(l<r){
        int mid=l+r>>1;
        if(box[mid]>=target)r=mid;
        else l=mid+1;
    }
    if(box[r]==target)return r;
    else return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>m>>x;
    for(int i=0;i<n;i++)cin>>A[i];
    for(int i=0;i<m;i++)cin>>B[i];

    if(n<m){
        for(int i=0;i<n;i++){
            int target=x-A[i];
            int res=myfind(target,B,m-1);
            if(res!=-1){
                cout<<i<<" "<<res;
                return 0;
            }
        }
    }else{
        for(int i=0;i<m;i++){
            int target=x-B[i];
            int res=myfind(target,A,n-1);
            if(res!=-1){
                cout<<res<<" "<<i;
                return 0;
            }
        }
    }

}
