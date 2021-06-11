/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-11 19:27:28
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=100010,M=200010;

struct edge{
    int a,b,w;

}e[M];


int p[N];
int cnt[N];
int n,m;

bool cmp1(edge e1,edge e2){
    return e1.w<e2.w;
}

int find(int node){
    if(p[node]!=node)p[node]=find(p[node]);
    return p[node];
}

int kruskal(){
    int res=0;
    sort(e,e+m,cmp1);
    for(int i=0;i<m;i++){
        edge tmp=e[i];
        if(find(tmp.a)!=find(tmp.b)){
            cnt[find(tmp.b)]+=cnt[find(tmp.a)];
            p[find(tmp.a)]=find(tmp.b);
            res+=tmp.w;
        }
    }
    if(cnt[find(1)]!=n)return -1;
    else return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        p[i]=i;
        cnt[i]=1;
    }

    int v1,v2,v3;
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>v3;
        e[i]={a:v1,b:v2,w:v3};
    }

    int res=kruskal();

    if(res==-1)cout<<"impossible";
    else cout<<res;

}
