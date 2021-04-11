/*
 * @Description: 很笨的回溯 TLE
 * @Author: Marcel
 * @Date: 2021-04-10 17:01:50
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

void handle(vector<vector<int>>& res,vector<int>tmp){
    sort(tmp.begin(),tmp.end());
    bool flag=true;
    for(int i=0;i<res.size();i++){
        if(res[i]==tmp){
            flag=false;
            break;
        }
    }
    if(flag)res.push_back(tmp);
}

void dfs(vector<int>& candidates,int target,vector<int>& tmp,int sum,vector<vector<int>> &res,vector<int> & intmp,int i){
    if(sum==target){
        /*res.push_back(tmp);*/
        /*去重*/
        handle(res,tmp);
        intmp[i]=0;
        tmp.pop_back();
        return;
    }
    if(sum<target){
        for(int i=0;i<candidates.size();i++){
            //元素在tmp中，则跳过
            if(!intmp[i]){
                intmp[i]=1;
                tmp.push_back(candidates[i]);
                dfs(candidates,target,tmp,sum+tmp.back(),res,intmp,i);
            }
        }
        intmp[i]=0;
        tmp.pop_back();
    }
    if(sum>target){
        intmp[i]=0;
        tmp.pop_back();
        return;
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>res;
    vector<int>tmp;
    vector<int>intmp((int)(candidates.size()),0);
    dfs(candidates,target,tmp,0,res,intmp,0);
    return res;
}

vector<int>vec={10,1,2,7,6,1,5};
int main(void){
    combinationSum2(vec,8);
}
