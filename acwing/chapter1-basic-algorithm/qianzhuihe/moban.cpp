/*
 * @Description: 前缀和，求连续数组元素和
 * @Author: Marcel
 * @Date: 2021-05-10 13:39:41
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a[100010];
int s[100010];
int n,m;

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    s[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i-1];
    }

    int l,r;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<"\n";
    }
}

