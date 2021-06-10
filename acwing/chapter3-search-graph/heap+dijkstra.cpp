/*
 * @Description: 堆优化迪杰斯特拉
 * @Author: Marcel
 * @Date: 2021-06-11 00:32:33
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include<queue>
#include<map>

using namespace std;

typedef pair<int,int> PII;

const int N=150010;

vector<PII> lst[N];
int dist[N];
bool st[N];

int n,m;

int heap_dijk(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});

    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();

        int v=t.second,length=t.first;

        /*可能会多次向堆中添加某点，松弛过的点，不再访问*/
        if(st[v])continue;
        st[v]=true;

        for(int i=0;i<lst[v].size();i++){
            int j=lst[v][i].second;
            /*松弛t：对于t的每个下一节点j*/
            /*源点到t的距离+t到j的距离  更新源点到j的距离*/
            /*更新成功了，则把新点作为t放入堆中*/
            if(dist[j]>length+lst[v][i].first){
                dist[j]=length+lst[v][i].first;
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
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

    cout<<heap_dijk();

}
