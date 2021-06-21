/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-19 19:46:07
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=1010;
int dp[N][N];

int n,m;
string s1,s2;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>s1;
    cin>>m>>s2;

    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(s1[i]==s2[j])dp[i+1][j+1]=dp[i][j];
            else dp[i+1][j+1]=min(dp[i][j+1]+1,dp[i][j]+1);
        }
    }
    cout<<dp[n][m];
}
