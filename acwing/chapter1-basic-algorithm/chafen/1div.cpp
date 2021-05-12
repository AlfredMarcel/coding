/*
 * @Description: 一维差分数组
 * @Author: Marcel
 * @Date: 2021-05-10 14:26:40
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,m;
int a[100010];
int b[100010];

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];

    int l,r,c;
    for(int i=0;i<m;i++){
        cin>>l>>r>>c;
        b[l]+=c;
        b[r+1]-=c;
    }

    for(int i=1;i<=n;i++){
        a[i]=b[i]+a[i-1];
        cout<<a[i]<<" ";
    }
}

