/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-19 15:20:22
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=1010;
int n,m;
string s1,s2;
int dp[N][N];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    cin>>s1>>s2;

    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(s1[i]==s2[j])dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    cout<<dp[n][m];

}
