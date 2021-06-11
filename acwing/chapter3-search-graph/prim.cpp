/*
 * @Description: prim算法
 * @Author: Marcel
 * @Date: 2021-06-11 18:28:03
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=510;

int g[N][N];
int dist[N];
bool st[N];

int n,m;

int prim(){
    memset(dist,0x3f,sizeof dist);

    int res=0;
    for(int i=0;i<n;i++){
        //找距离集合最近的一个点
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[j]<dist[t]))t=j;
        }
        //最近的一个是无穷，说明没找到
        if(i!=0&&dist[t]==0x3f3f3f3f)return -1;
        if(i!=0)res+=dist[t];
        st[t]=true;

        //每有一个新点加入集合，就更新全部结点到集合的最短距离
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],g[t][j]);
        }
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    int v1,v2,v3;
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>v3;
        g[v1][v2]=min(v3,g[v1][v2]);
        g[v2][v1]=min(v3,g[v2][v1]);
    }

    int res=prim();
    if(res==-1)cout<<"impossible";
    else cout<<res;
}

