/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-07 08:12:34
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<int>& nums,int index,int& sum,int target){
    if(index==nums.size()){
        if(target==0)sum++;
        return;
    }
    dfs(nums,index+1,sum,target-nums[index]);
    dfs(nums,index+1,sum,target+nums[index]);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int sum=0;
    int index=0;
    dfs(nums,index,sum,target);
    return sum;
}

int main(void){
    vector<int>vec={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int target=3;
    cout<<findTargetSumWays(vec,target);
}
