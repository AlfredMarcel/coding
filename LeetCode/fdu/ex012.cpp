/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-09-23 09:30:36
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<algorithm>

using namespace std;

const int N=1000;

int n;
int grid[N][N];

int main(void){
    unordered_map<int,int>tab;
    
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1-i;j++){
            if(tab.find(i)==tab.end()){
                tab[i]=grid[i][j];
            }else{
                tab[i]=max(tab[i],grid[i][j]);
            }

            if(tab.find(j)==tab.end()){
                tab[j]=grid[i][j];
            }else{
                tab[j]=max(tab[j],grid[i][j]);
            }
        }
    }

    int res=-1;
    int length=0x33333333;

    for(auto p:tab){
        if(p.second<length)res=p.first;
    }
    cout<<res;

}
