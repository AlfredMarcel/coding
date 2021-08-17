/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-04 13:15:34
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

const int N=12; 

class Solution {

    vector<int> tab[N];
    queue<int>que;
    int sum=0;
    

public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        for(auto v:relation){
            tab[v[0]].push_back(v[1]);
        }

        vector<int>mark(n,0);
        int current=0;

        que.push(0);
        mark[0]=0;
        while(!que.empty()){
            int head=que.front();
            que.pop();

            
            if(mark[head]>=k)break;
            if(mark[head]==current){sum=0;}

            for(int i=0;i<tab[head].size();i++){
                que.push(tab[head][i]);
                mark[tab[head][i]]=mark[head]+1;
                current=mark[tab[head][i]];
                if(tab[head][i]==n-1)sum++;
            }
        }
        return sum;

    }
};

int main(void){
    
}
