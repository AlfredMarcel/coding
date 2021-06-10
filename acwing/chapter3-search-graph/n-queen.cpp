/*
 * @Description: n皇后
 * @Author: Marcel
 * @Date: 2021-06-10 14:43:37
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int col[20],ldg[30],rdg[30];
int n;
vector<vector<int>>res;
vector<int>tmp;

void dfs(int length){

    if(length==n+1){
        res.push_back(tmp);
        return;
    }

    int raw=length;
    for(int i=1;i<=n;i++){
        //列、左右对角线均无冲突
        if(!col[i]&&!ldg[n-raw+i]&&!rdg[raw+i-1]){
            col[i]=ldg[n-raw+i]=rdg[raw+i-1]=1;
            tmp.push_back(i);
            dfs(length+1);
            tmp.pop_back();
            col[i]=ldg[n-raw+i]=rdg[raw+i-1]=0;
        }
    }
}

int main(void){
    cin>>n;

    dfs(1);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            for(int k=0;k<n;k++){
                if(k==res[i][j]-1)cout<<'Q';
                else cout<<'.';
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}
