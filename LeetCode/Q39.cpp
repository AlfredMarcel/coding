/*
 * @Description: 回溯法，使用map判断组合是否重复，很慢
 * @Author: Marcel
 * @Date: 2021-04-10 10:54:18
 */

#include <iostream>
#include <vector>
#include <string>
#include<map>

using namespace std;


bool judge(vector<map<int,int>>& tab,map<int,int>& a){
    for(int i=0;i<tab.size();i++){
        if(tab[i]==a)return false;
    }
    return true;
}

map<int,int> count(vector<int>& a){
    map<int,int>res;
    for(int i=0;i<a.size();i++){
        res[a[i]]++;
    }
    return res;
}

void dfs(vector<int>& nums,int t,vector<vector<int>> &res,int sum,vector<int>&tmp,vector<map<int,int>>&tab){

    if(t==sum){
        map<int,int>mptmp=count(tmp);
        if(judge(tab,mptmp)){
            res.push_back(tmp);
            tab.push_back(mptmp);
        }
        tmp.pop_back();
        return ;
    }
    if(t>sum){
        for(int i=0;i<nums.size();i++){
            tmp.push_back(nums[i]);
            dfs(nums,t,res,sum+nums[i],tmp,tab);
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
    vector<map<int,int>>tab;
    dfs(candidates,target,res,0,tmp,tab);
    return res;
}

vector<int>vec={2,3,6,7};

int main(void){
    combinationSum(vec,7);
}
