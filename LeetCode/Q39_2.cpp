/*
 * @Description: 回溯法，保存排序结果来判断组合是否重复，还是慢，比map快一点
 * @Author: Marcel
 * @Date: 2021-04-10 11:50:38
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

void handle(vector<vector<int>>&res,vector<int>tmp){
    
    bool flag=true;
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<res.size();i++){
        if(res[i]==tmp){
            flag=false;
            break;
        }
    }
    if(flag)res.push_back(tmp);
}

void dfs(vector<int>& nums,int t,vector<vector<int>> &res,int sum,vector<int>&tmp){

    if(t==sum){
        /*
        if(judge(res,tmp)){
            res.push_back(tmp);
        }
        */
        handle(res,tmp);
        tmp.pop_back();
        return ;
    }
    if(t>sum){
        for(int i=0;i<nums.size();i++){
            tmp.push_back(nums[i]);
            dfs(nums,t,res,sum+nums[i],tmp);
        }
        tmp.pop_back();
    }
    if(t<sum){
        tmp.pop_back();
        return;
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>res;
    vector<int>tmp;
    dfs(candidates,target,res,0,tmp);
    return res;
}

int main(void){
    
}
