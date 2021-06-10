/*
 * @Description: 宽搜走迷宫
 * @Author: Marcel
 * @Date: 2021-06-10 15:25:48
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

const int N=110;

int maze[N][N];
int dis[N][N];


int n,m;
int res;

vector<pair<int,int>>direct={{1,0},{0,1},{-1,0},{0,-1}};

int bfs(){
    queue<pair<int,int>>que;
    que.push({1,1});

    memset(dis,-1,sizeof dis);
    dis[1][1]=0;

    while(!que.empty()){
        pair<int,int>head=que.front();
        que.pop();
        for(int i=0;i<direct.size();i++){
            pair<int,int>tmp={head.first+direct[i].first,head.second+direct[i].second};
            if(dis[tmp.first][tmp.second]==-1&&tmp.first>=1&&tmp.first<=n&&tmp.second>=1&&tmp.second<=m&&maze[tmp.first][tmp.second]==0){
                que.push(tmp);
                dis[tmp.first][tmp.second]=dis[head.first][head.second]+1;
            }
        }
    }
    return dis[n][m];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>maze[i][j];
        }
    }

    cout<<bfs();

}

