/*
 * @Description: 区间dp  石子合并
 * @Author: Marcel
 * @Date: 2021-06-19 15:35:51
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=310;
int dp[N][N];
int s[N];

int box[N];
int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    for(int i=0;i<n;i++)cin>>box[i];
    for(int i=1;i<=n;i++)s[i]=s[i-1]+box[i-1];

    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            dp[i][j]=1e8;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
            }
        }
    }
    cout<<dp[1][n];

}

