/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-10 11:29:27
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N=100010;

int p[N],se[N];

int n,m;

int find(int v1){
    if(p[v1]!=v1) p[v1]=find(p[v1]);
    return p[v1];
}

void connect(int v1,int v2){
    if(find(v1)!=find(v2)){
        se[find(v2)]+=se[find(v1)];
        p[find(v1)]=find(v2);
    }
}

void query1(int v1,int v2){
    if(find(v1)==find(v2))cout<<"Yes\n";
    else cout<<"No\n";
}

void query2(int v1){
    cout<<se[find(v1)]<<"\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;

    for(int i=0;i<n;i++){
        p[i]=i;
        se[i]=1;
    }

    string op;
    int v1,v2;
    for(int i=0;i<m;i++){
        cin>>op;
        if(op=="Q2"){
            cin>>v1;
            query2(v1);
        }else if(op=="Q1"){
            cin>>v1>>v2;
            query1(v1,v2);
        }else{
            cin>>v1>>v2;
            connect(v1,v2);
        }
    }
}
