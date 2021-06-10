/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-10 14:24:47
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

int n,m;
priority_queue<int,vector<int>,greater<int>>heap;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        heap.push(tmp);
    }

    for(int i=0;i<m;i++){
        cout<<heap.top()<<" ";
        heap.pop();

    }
}
