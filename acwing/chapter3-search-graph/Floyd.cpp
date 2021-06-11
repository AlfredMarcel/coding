/*
 * @Description: Floyd算法 
 * @Author: Marcel
 * @Date: 2021-06-11 14:48:39
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=210;

int n,m,k;
int d[N][N];

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    memset(d,0x3f,sizeof d);

    cin>>n>>m>>k;
    int v1,v2,v3;
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>v3;
        d[v1][v2]=min(d[v1][v2],v3);
    }
    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }

    floyd();

    for(int i=0;i<k;i++){
        cin>>v1>>v2;
        if(d[v1][v2]>0x3f3f3f3f/2)cout<<"impossible\n";
        else cout<<d[v1][v2]<<"\n";
    }
    
}
