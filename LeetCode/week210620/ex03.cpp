/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-20 10:42:51
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    for(int i=0;i<grid2.size();i++){
        for(int j=0;j<grid2[i].size();j++){
            grid1[i][j]+=grid2[i][j];
            grid2[i][j]=0;
        }
    }
    int sum=0;
    int m=grid1.size();
    int n=grid1[0].size();
    for(int i=0;i<grid1.size();i++){
        for(int j=0;j<grid1[i].size();j++){
            if(grid1[i][j]==2){
                bool flag=true;
                if(i>=0&&j>=0&&i<m-1&&j<n-1){
                    if(grid1[i][j+1]==2||grid1[i+1][j]==2)flag=false;
                }else if(i==m-1&&j<n-1){
                    if(grid1[i][j+1]==2)flag=false;
                }else if(i<m-1&&j==n-1){
                    if(grid1[i+1][j]==2)flag=false;
                }
                if(flag)sum++;
            }
        }
    }
    return sum;
    
}

int main(void){
    
}
