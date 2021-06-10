/*
 * @Description: 并查集 合并集合
 * @Author: Marcel
 * @Date: 2021-06-09 11:43:56
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*每个元素的祖先*/
int q[100010];
int n,m;

int find(int a){
    if(q[a]!=a)q[a]=find(q[a]);
    return q[a];
}

void join(int a,int b){
    q[find(a)]=find(b);
}

void judge(int a,int b){
    if(find(a)==find(b))cout<<"Yes\n";
    else cout<<"No\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;

    for(int i=0;i<n;i++)q[i]=i;

    char op;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>op>>a>>b;
        if(op=='M')join(a,b);
        else if(op=='Q')judge(a,b);
    }
}
