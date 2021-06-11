/*
 * @Description: spfa判负环
 * @Author: Marcel
 * @Date: 2021-06-11 14:07:05
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include<queue>

using namespace std;

const int N=2010;

typedef pair<int,int> PII;
vector<PII> lst[N];
int dist[N],cnt[N];
bool st[N];

int n,m;

bool judge_spfa(){

    /*不用赋dist初值,也就是全0，相当于虚拟了一个0号结点，到所有1-n结点距离都是0，让图连通*/

    queue<int>que;
    for(int i=1;i<=n;i++){
        que.push(i);
        st[i]=true;
    }

    while(!que.empty()){
        int t=que.front();
        que.pop();
        st[t]=false;

        for(int i=0;i<lst[t].size();i++){
            int node=lst[t][i].second;
            int length=lst[t][i].first;
            if(dist[node]>dist[t]+length){
                dist[node]=dist[t]+length;
                cnt[node]=cnt[t]+1;
                if(cnt[node]>=n)return true;
                if(!st[node]){
                    que.push(node);
                    st[node]=true;
                }
                
            }
        }
    }
    return false;

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

    if(judge_spfa())cout<<"Yes";
    else cout<<"No";
}

