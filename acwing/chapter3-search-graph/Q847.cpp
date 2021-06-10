/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-10 21:57:23
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include<cstring>

using namespace std;

const int N=100010;
vector<int>lst[N];
int n,m;
bool st[N];
int dis[N];

int bfs(){
    queue<int>que;
    que.push(1);
    st[1]=true;
    dis[1]=0;

    while(!que.empty()){
        int head=que.front();
        que.pop();

        for(int i=0;i<lst[head].size();i++){
            int j=lst[head][i];
            if(!st[j]){
                st[j]=true;
                que.push(j);
                dis[j]=dis[head]+1;
            }
        }
    }
    return dis[n];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    int v1,v2;
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        lst[v1].push_back(v2);
    }

    memset(dis,-1,sizeof dis);

    cout<<bfs();

}
