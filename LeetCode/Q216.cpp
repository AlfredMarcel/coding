/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-10 10:50:13
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>>res={};
vector<int>num={1,2,3,4,5,6,7,8,9};
vector<int>save(9,0);


void dfs(int k,int n,vector<int>& tmp,int sum,int index){
    if(tmp.size()<k){
        for(int i=index;i<num.size();i++){
            if(!save[i]){
                if(sum+num[i]>n)break;
                tmp.push_back(num[i]);
                save[i]=1;
                dfs(k,n,tmp,sum+num[i],i+1);
            }
        }
        tmp.pop_back();
        save[index-1]=0;
    }else{
        if(sum==n){
            res.push_back(tmp);
        }
        tmp.pop_back();
        save[index-1]=0;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    
    vector<int>tmp;
    dfs(k,n,tmp,0,0);
    return res;
}

int main(void){
    vector<int>a(3,0);
    cout<<a[0]<<a[1]<<a[2];
}
