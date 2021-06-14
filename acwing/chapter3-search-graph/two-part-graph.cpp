/*
 * @Description: 染色法判二分图
 * @Author: Marcel
 * @Date: 2021-06-11 20:54:31
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N=100010;

vector<int> lst[N];
bool st[N];
int color[N];

int n,m;

bool dfs(int id,int col){

    st[id]=true;
    color[id]=col;

    for(int i=0;i<lst[id].size();i++){
        int j=lst[id][i];
        if(!st[j]){
            if(!dfs(j,3-col))return false;
            //return dfs(j,3-col); 这样写就错了
        }else{
            if(color[j]==col)return false;
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    int v1,v2;
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        lst[v1].push_back(v2);
        lst[v2].push_back(v1);
    }

    bool flag=true;
    for(int i=1;i<=n;i++){
        if(!st[i]){
            if(!dfs(i,1)){
                flag=false;
                break;
            }
        }
    }

    if(flag){
        cout<<"Yes";
    }else{
        cout<<"No";
    } 
}
