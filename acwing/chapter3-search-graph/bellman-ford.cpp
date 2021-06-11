/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-11 01:20:30
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>

using namespace std;

const int N=510;
const int M=10010;

int dist[N];
int last[N];
int n,m,k;

struct Edge{
    int a,b,w;

}edges[M];


void b_f(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    /*迭代k次*/
    for(int i=0;i<k;i++){
        memcpy(last,dist,sizeof dist);
        for(int j=0;j<m;j++){
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            dist[b]=min(dist[b],last[a]+w);
        }
    }
    if(dist[n]>0x3f3f3f3f/2) cout<<"impossible";
    else cout<<dist[n];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m>>k;
    int v1,v2,v3;
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>v3;
        edges[i]={v1,v2,v3};
    }

    b_f();
}
