/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 10:29:31
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include<algorithm>

using namespace std;

struct mess{
    int intime;
    int dotime;
    int index;

    mess(int a,int b,int c){
        intime=a;
        dotime=b;
        index=c;
    }

    mess(){

    }
};

bool operator < (mess a,mess b){
    if(a.dotime==b.dotime)return a.index>b.index;
    return a.dotime>b.dotime;
}

bool cmp(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}

vector<int>res;
priority_queue<mess>que;

vector<int> getOrder(vector<vector<int>>& tasks) {
    for(int i=0;i<tasks.size();i++){
        tasks[i].push_back(i);
    }
    sort(tasks.begin(),tasks.end(),cmp);
    int count=0;
    int size=tasks.size();
    int time=0;
    int work_time=0;
    while(count!=size){
        time++;
        int i=count+que.size();
        for(;i<tasks.size();i++){
            if(tasks[i][0]>time)break;
            que.push(mess(tasks[i][0],tasks[i][1],tasks[i][2]));
        }
        if(!que.empty()&&work_time==0){
            res.push_back(que.top().index);
            count++;
            work_time=que.top().dotime;
            que.pop();
        }
        if(work_time!=0)work_time--;
    }
    return res;
}

int main(void){
    vector<vector<int>>vecc={{19,13},{16,9},{21,10},{32,25},{37,4},{49,24},{2,15},{38,41},{37,34},{33,6},{45,4},{18,18},{46,39},{12,24}};
    getOrder(vecc);
}
