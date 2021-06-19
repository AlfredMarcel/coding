/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-18 13:22:03
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=510;
const int INF=-0x3f3f3f3f;

int box[N][N];
int dp[N][N];

int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    memset(box,INF,sizeof box);
    memset(dp,INF,sizeof dp);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>box[i][j];
        }
    }

    dp[0][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+box[i][j];
        }
    }
    int res=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        res=max(res,dp[n][i]);
    }
    cout<<res;
}
