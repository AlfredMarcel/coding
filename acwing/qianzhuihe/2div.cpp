/*
 * @Description: 二维前缀和
 * @Author: Marcel
 * @Date: 2021-05-10 13:48:12
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,m,q;
int a[1010][1010];
int s[1010][1010];

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i-1][j-1];
        }
    }
    int x1,y1,x2,y2;
    for(int i=0;i<q;i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<(s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1])<<"\n";
    }
}

