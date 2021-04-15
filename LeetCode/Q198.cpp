/*
 * @Description: 搜索，超时了
 * @Author: Marcel
 * @Date: 2021-04-15 00:56:38
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

void dfs(vector<int>& nums,int &res,int index,int sum){
    res=max(res,sum);
    if(index==0){
        for(int i=0;i<nums.size();i++){
            if(i>=3)break;
            dfs(nums,res,i+1,sum+nums[i]);
        }
    }else{
        for(int i=index+1;i<nums.size();i++){
            if(i-index>3)break;
            dfs(nums,res,i+1,sum+nums[i]);
        }
    }
}

int rob(vector<int>& nums){
    int res=0;
    if(!nums.empty())dfs(nums,res,0,0);
    return res;
}

int main(void){
    vector<int>vec={1,9,1,1,12,1};
    cout<<rob(vec);
}
