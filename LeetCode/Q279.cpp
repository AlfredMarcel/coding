/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-11 10:24:01
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int numSquares(int n) {
    vector<int>nums;
    int i=1;
    while(i*i<=n){
        nums.push_back(i*i);
        i++;
    }

    vector<int>dp(n+1,10010);
    dp[0]=0;
    for(int i=0;i<nums.size();i++){
        for(int j=nums[i];j<=n;j++){
            dp[j]=min(dp[j-nums[i]]+1,dp[j]);
        }
    }

    return dp[n];
}

int main(void){
    int n;
    cin>>n;
    cout<<numSquares(n);
}
