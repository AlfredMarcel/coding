/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-10 23:49:28
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=10;

int g[N][N];
int dist[N];
bool st[N];

int n,m;

int dijk(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    for(int i=0;i<n-1;i++){
        int t=-1;
        //在未确定最短路的点中，找到距离dist[t]最小的t
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j]))t=j;
        }
        //用t更新其他点的距离
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
        //此之后，到t点的路径必然是最短的
        st[t]=true;
    }

    if(dist[n]==0x3f3f3f3f)return -1;
    else return dist[n];
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie();

    memset(g,0x3f,sizeof g);

    cin>>n>>m;
    int v1,v2,v3;
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>v3;
        if(!g[v1][v2]||g[v1][v2]>v3)g[v1][v2]=v3;
    }

    cout<<dijk();

}
