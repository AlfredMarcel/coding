/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-13 11:17:51
 */
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

vector<vector<int>>res={};


void dfs(vector<int>& candidates,int& target,vector<int>& tmp,int sum,int index){
    if(target==sum){
        //handle(tmp);
        res.push_back(tmp);
        tmp.pop_back();
        return;
    }
    if(target>sum){
        for(int i=index;i<candidates.size();i++){
            if (i>index && candidates[i]==candidates[i-1]) continue; // 去重
            /*排序后，可以剪枝*/
            if(sum+candidates[i]>target){
                break;
            }
            tmp.push_back(candidates[i]);
            dfs(candidates,target,tmp,sum+candidates[i],i+1);    
        }
        if(!tmp.empty())tmp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){    
    sort(candidates.begin(),candidates.end());
    vector<int>tmp={};
    dfs(candidates,target,tmp,0,0);
    return res;
}

int main(void){
    vector<int>a={1,1,1,3,3,5};
    combinationSum2(a,5);
    cout<<"ok";
}
