/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-26 00:04:29
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {

    unordered_map<string,bool>st;
    unordered_map<string,int>dis;
    vector<pair<int,int>>handle={{1,0},{-1,0},{0,1},{0,-1}};
    string target="123450";

public:
    void find0(int &x,int &y,vector<vector<int>>& tmp){
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(tmp[i][j]==0){
                    x=i;
                    y=j;
                    return;
                }
            }
        }
    }

    string parse(vector<vector<int>>& board){
        string tmp;
        for(auto v:board)for(int i:v)tmp+=i+'0';
        return tmp;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>>que;
        que.push(board);
        st[parse(board)]=true;
        dis[parse(board)]=0;

        while(!que.empty()){
            auto tmp=que.front();
            
            string old_str=parse(tmp);
            if(old_str==target)return dis[old_str];
            //find 0 x,y
            int x,y;
            find0(x,y,tmp);
            for(int i=0;i<handle.size();i++){
                int nx=x+handle[i].first,ny=y+handle[i].second;
                if(nx>=0&&nx<=1&&ny>=0&&ny<=2){
                    tmp[x][y]=tmp[nx][ny];
                    tmp[nx][ny]=0;
                    string tmp_str=parse(tmp);
                    if(!st[tmp_str]){
                        st[tmp_str]=true;
                        dis[tmp_str]=dis[old_str]+1;
                        que.push(tmp);
                    }
                    tmp=que.front();
                }
            }
            que.pop();
        }
        return -1;
    }
};

int main(void){
    Solution* s=new Solution();
    vector<vector<int>>vec={{1,2,3},{4,0,5}};
    cout<<s->slidingPuzzle(vec);
}
