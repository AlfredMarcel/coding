/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-15 00:45:59
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int r(vector<int> nums){
    if(nums.size()==1)return nums[0];
    if(nums.size()==2)return max(nums[0],nums[1]);
    int dp[128];
    int i=0;
    for(;i<nums.size();i++){
        if(i==0)dp[i]=nums[i];
        else if(i==1)dp[i]=max(dp[i-1],nums[i]);
        else dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[i-1];
}

int rob(vector<int>& nums) {
    if(nums.size()==0)return 0;
    if(nums.size()==1)return nums[0];
    return max(r(vector<int>(nums.begin(),nums.end()-1)),r(vector<int>(nums.begin()+1,nums.end())));
}

int main(void){
     
}
