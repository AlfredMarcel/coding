/*
 * @Description: dp解法
 * @Author: Marcel
 * @Date: 2021-04-15 14:15:37
 */
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int rob(vector<int>& nums){
    if(nums.empty())return 0;
    if(nums.size()==1)return nums[0];
    if(nums.size()==2)return max(nums[0],nums[1]);
    vector<int>dp(101,0);
    int i;
    for(i=0;i<nums.size();i++){
        if(i==0)dp[i]=nums[i];
        else if(i==1)dp[i]=max(dp[i-1],nums[i]);
        else dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[i-1];
}

int main(void){
    vector<int>vec={1,2,3,1,1,1,1,1,1,1,1,1,1,1,1};
    cout<<rob(vec);
}
