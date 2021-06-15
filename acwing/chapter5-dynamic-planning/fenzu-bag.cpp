/*
 * @Description: 分组背包,就是以组为单位的01背包
 * @Author: Marcel
 * @Date: 2021-06-15 16:47:06
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=110,M=110;

int vv[N][N],ww[N][N],ss[N],dp[M];

int n,v;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>v;
    for(int i=1;i<=n;i++){
        cin>>ss[i];
        for(int j=1;j<=ss[i];j++){
            cin>>vv[i][j]>>ww[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=v;j>=0;j--){
            for(int k=1;k<=ss[i];k++){
                if(vv[i][k]<=j){
                    dp[j]=max(dp[j],dp[j-vv[i][k]]+ww[i][k]);
                }
            }
        }
    }
    cout<<dp[v];
    
}


