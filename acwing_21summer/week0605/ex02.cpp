/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-05 19:53:54
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int T,n,k;
int q[10];

int main(void){
    cin.sync_with_stdio(false);
    cin.tie();

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>k;
        long long tmp=0;
        for(int j=0;j<n;j++){
            cin>>q[j];
        }
        sort(q,q+n);
        for(int j=0;j<=k;j++){
            tmp+=q[n-j-1];
        }
        cout<<tmp<<"\n";
    }
}
