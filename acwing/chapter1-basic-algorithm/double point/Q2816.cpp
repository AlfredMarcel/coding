/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-12 16:20:11
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,m;
int a[100010],b[100010];

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int i=0,j=0;
    for(;i<m;i++){
        if(a[j]==b[i])j++;
        if(j==n)break;
    }
    if(j==n)cout<<"Yes";
    else cout<<"No";
}
