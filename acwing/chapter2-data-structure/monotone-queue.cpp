/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-01 16:51:33
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

deque<int>minhead;
deque<int>maxhead;

int n,k;
int q[1000010];

int main(void){
    cin.sync_with_stdio(false);
    cin.tie();

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>q[i];
    }

    //单调队列里存的是下标
    for(int i=0;i<n;i++){
        //队首元素划出了窗口，则出队
        if(!minhead.empty()&&minhead.front()<=i-k)minhead.pop_front();

        //维护单调递增的队列：大于等于新入队元素的队尾元素全部pop
        while(!minhead.empty()&&q[minhead.back()]>=q[i])minhead.pop_back();
        minhead.push_back(i);

        if(i>=k-1)cout<<q[minhead.front()]<<" ";
    }

    cout<<"\n";

    for(int i=0;i<n;i++){

        if(!maxhead.empty()&&maxhead.front()<=i-k)maxhead.pop_front();

        while(!maxhead.empty()&&q[maxhead.back()]<=q[i])maxhead.pop_back();
        maxhead.push_back(i);

        if(i>=k-1)cout<<q[maxhead.front()]<<" ";

    }
}
