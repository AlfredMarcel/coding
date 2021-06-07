/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-02 09:11:52
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*超时*/

bool checkSubarraySum(vector<int>& nums, int k) {
    vector<int>dp;
    bool flag=false;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<dp.size();j++){
            dp[j]=(dp[j]+nums[i])%k;
            if(dp[j]==0)return true;
        }
        dp.push_back(nums[i]%k);
    }
    return flag;
}



int main(void){
    
}
