/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-01 14:32:26
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N=100010,M=1000010;
int n,m;
char p[N],s[M];
int nxt[N];

int main(void){
    
    cin>>n>>p+1>>m>>s+1;

    for(int i=2,j=0;i<=n;i++){
        while(j && p[i]!=p[j+1])j=nxt[j];
        if(p[i]==p[j+1])j++;
        nxt[i]=j;
    }

    for(int i=1,j=0;i<=m;i++){

        while(j && s[i]!=p[j+1])j=nxt[j];
        if(s[i]==p[j+1])j++;
        if(j==n){
            cout<<i-j<<" ";
            j=nxt[j];
        }
    }

}
