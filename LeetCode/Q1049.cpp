/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-08 09:05:23
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    int sum=accumulate(stones.begin(),stones.end(),0);
    vector<int>dp(sum/2+1);
    for(int i=0;i<stones.size();i++){
        for(int j=sum/2;j>=stones[i];j--){
            dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
        }
    }
    return sum-dp[sum/2]*2;        
} 

int main(void){
    vector<int>vec={31,26,33,21,40};
    cout<<lastStoneWeightII(vec);
}
