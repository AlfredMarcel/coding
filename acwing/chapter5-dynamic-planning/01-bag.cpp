/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-14 11:37:11
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=1010;

int vv[N],ww[N];
int dp[N];
int n,m;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>vv[i]>>ww[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=vv[i];j--){
            dp[j]=max(dp[j],dp[j-vv[i]]+ww[i]);
        }
    }
    cout<<dp[m];
}
