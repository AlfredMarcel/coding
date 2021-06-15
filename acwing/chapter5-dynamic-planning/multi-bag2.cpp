/*
 * @Description: 把多重背包拆成二进制优化的01背包
 * @Author: Marcel
 * @Date: 2021-06-15 15:25:43
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N=12010,V=2010;

int vv[N],ww[N],dp[V];

int n,v;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>v;
    int t=0;
    int v1,v2,v3;
    for(int i=0;i<n;i++){
        cin>>v1>>v2>>v3;
        int k=1;
        while(k<=v3){
            t++;
            vv[t]=v1*k;
            ww[t]=v2*k;
            v3-=k;
            k*=2;
        }
        if(v3>0){
            t++;
            vv[t]=v1*v3;
            ww[t]=v2*v3;
        }
    }

    for(int i=1;i<=t;i++){
        for(int j=v;j>=vv[i];j--){
            dp[j]=max(dp[j],dp[j-vv[i]]+ww[i]);
        }
    }
    cout<<dp[v];
}

