/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-10 14:53:10
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,m,q;
int a[1010][1010];
int b[1010][1010];

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[i][j]=a[i+1][j+1]-a[i][j+1]-a[i+1][j]+a[i][j];
        }
    }
    int x1,y1,x2,y2,c;
    for(int i=0;i<q;i++){
        cin>>x1>>y1>>x2>>y2>>c;
        b[x1-1][y1-1]+=c;
        b[x1-1][y2]-=c;
        b[x2][y1-1]-=c;
        b[x2][y2]+=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+b[i-1][j-1];
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

}
