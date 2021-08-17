/*
 * @Description: ex02
 * @Author: Marcel
 * @Date: 2021-07-06 09:58:25
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

//假定n<=100000
const int N=10;
int a[N];
int dp[N];
int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    for(int i=1;i<=n;i++){
        /*滚动数组*/
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int k=1;k<=n;k++){
            dp[k]=max(dp[k],dp[k-1])+a[k];
        }
    }
    cout<<dp[n];
}


/*二维的写法，可以优化成一维的dp*/
/*
//假定N<=1000
const int N=1010;
int a[N][N];
int dp[N][N];
int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    cout<<dp[n][n];
}
*/