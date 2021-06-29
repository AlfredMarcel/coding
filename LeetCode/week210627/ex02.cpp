/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-27 10:29:05
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

class Solution {
    int m,n;
    vector<vector<int>>tmp;
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int big_idx=0,small_idx=0;
        if(m>=n){
            while(n>grid[0].size()/2){
                vector<int>t;
                int b=big_idx,s=small_idx;
                for(;s<n;s++)t.push_back(grid[b][s]);
                s--;
                b++;
                for(;b<m;b++)t.push_back(grid[b][s]);
                b--;
                s--;
                for(;s>=small_idx;s--)t.push_back(grid[b][s]);
                s++;
                b--;
                for(;b>big_idx;b--)t.push_back(grid[b][s]);
                m--;
                n--;
                big_idx++;
                small_idx++;
                tmp.push_back(t);
            }
        }else{
            while(m>grid.size()/2){
                vector<int>t;
                int b=big_idx,s=small_idx;
                for(;b<n;b++)t.push_back(grid[s][b]);
                b--;
                s++;
                for(;s<m;s++)t.push_back(grid[s][b]);
                s--;
                b--;
                for(;b>=big_idx;b--)t.push_back(grid[s][b]);
                b++;
                s--;
                for(;s>small_idx;s--)t.push_back(grid[s][b]);
                m--;
                n--;
                big_idx++;
                small_idx++;
                tmp.push_back(t);
            }
        }
        for(int i=0;i<tmp.size();i++){
            int j=tmp[i].size();
            int step=k%j;
            for(int p=0;p<step;p++){
                tmp[i].push_back(tmp[i][p]);
            }
            tmp[i].erase(tmp[i].begin(),tmp[i].begin()+step);
        }

        m=grid.size();
        n=grid[0].size();
        big_idx=0;
        small_idx=0;
        for(int i=0;i<tmp.size();i++){
            if(m>=n){
            while(n>grid[0].size()/2){
                int cnt=0;
                int b=big_idx,s=small_idx;
                for(;s<n;s++)grid[b][s]=tmp[i][cnt++];
                s--;
                b++;
                for(;b<m;b++)grid[b][s]=tmp[i][cnt++];
                b--;
                s--;
                for(;s>=small_idx;s--)grid[b][s]=tmp[i][cnt++];
                s++;
                b--;
                for(;b>big_idx;b--)grid[b][s]=tmp[i][cnt++];
                m--;
                n--;
                big_idx++;
                small_idx++;
                i++;
            }
        }else{
            while(m>grid.size()/2){
                int cnt=0;
                int b=big_idx,s=small_idx;
                for(;b<n;b++)grid[s][b]=tmp[i][cnt++];
                b--;
                s++;
                for(;s<m;s++)grid[s][b]=tmp[i][cnt++];
                s--;
                b--;
                for(;b>=big_idx;b--)grid[s][b]=tmp[i][cnt++];
                b++;
                s--;
                for(;s>small_idx;s--)grid[s][b]=tmp[i][cnt++];
                m--;
                n--;
                big_idx++;
                small_idx++;
                i++;
            }
        }
        }
        return grid;
    }
};

int main(void){
    Solution* s=new Solution();
    vector<vector<int>>vec={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int k=2;
    s->rotateGrid(vec,k);
}
