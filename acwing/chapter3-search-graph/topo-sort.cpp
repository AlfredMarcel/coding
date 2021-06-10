/*
 * @Description: 拓扑排序
 * @Author: Marcel
 * @Date: 2021-06-10 22:15:40
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

const int N=100010;
vector<int> lst[N];
int du[N];
vector<int>res;

int n,m;

void topo_sort(){

    queue<int>que;
    for(int i=1;i<=n;i++){
        if(!du[i])que.push(i);
    }

    while(!que.empty()){
        int head=que.front();
        res.push_back(head);
        que.pop();

        for(int i=0;i<lst[head].size();i++){
            int j=lst[head][i];
            du[j]--;
            if(!du[j])que.push(j);
        }
    }

    if(res.size()<n){
        cout<<"-1";
        return;
    }else{
        for(int item:res)cout<<item<<" ";
        return;
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    int v1,v2;
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        lst[v1].push_back(v2);
        du[v2]++;
    }

    topo_sort();

}

