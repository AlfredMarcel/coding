/*
 * @Description: 多重背包1:把多重背包拆成01背包
 * @Author: Marcel
 * @Date: 2021-06-15 14:27:33
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=10010;

int dp[N],vv[N],ww[N];

int n,v;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>v;
    int t=0;
    int v1,v2,v3;
    while(n--){
        cin>>v1>>v2>>v3;
        for(int i=0;i<v3;i++){
            t++;
            vv[t]=v1;
            ww[t]=v2;
        }
    }

    for(int i=1;i<=t;i++){
        for(int j=v;j>=vv[i];j--){
            dp[j]=max(dp[j],dp[j-vv[i]]+ww[i]);
        }
    }

    cout<<dp[v];
}
