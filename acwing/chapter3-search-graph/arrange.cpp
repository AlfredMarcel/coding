/*
 * @Description: 全排列
 * @Author: Marcel
 * @Date: 2021-06-10 14:32:23
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
int se[10];
vector<int>res;

void dfs(int length){
    if(length==n){
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!se[i]){
            se[i]=1;
            res.push_back(i);
            dfs(length+1);
            res.pop_back();
            se[i]=0;
        }
    }
}

int main(void){
    cin>>n;
    dfs(0);
}
