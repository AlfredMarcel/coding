/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-15 13:53:16
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N=1010;
int dp[N],vv[N],ww[N];

int n,m;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>vv[i]>>ww[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=vv[i];j<=m;j++){
            dp[j]=max(dp[j],dp[j-vv[i]]+ww[i]);
        }
    }
    cout<<dp[m];
}
