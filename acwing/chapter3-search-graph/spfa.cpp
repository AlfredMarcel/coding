/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-11 11:30:12
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include<queue>
#include<map>

using namespace std;

const int N=100010;

typedef pair<int,int> PII;
vector<PII> lst[N];
int dist[N];
bool st[N];

int n,m;

void spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    queue<int> que;
    que.push(1);
    st[1]=true;

    while(!que.empty()){
        int t=que.front();
        que.pop();

        /*弹出队列的点可能会再一次被加入*/
        st[t]=false;

        for(int i=0;i<lst[t].size();i++){
            int node=lst[t][i].second;
            int dis=lst[t][i].first;
            if(dist[node]>dist[t]+dis){
                dist[node]=dist[t]+dis;
                if(!st[node]){
                    que.push(node);
                    st[node]=true;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)cout<<"impossible";
    else cout<<dist[n];
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    int v1,v2,v3;
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>v3;
        lst[v1].push_back({v3,v2});
    }

    spfa();

}
