/*
 * @Description: PAT A 1014   22/30  最后两个测试点没过
 * @Author: Marcel
 * @Date: 2021-04-01 15:43:47
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

struct wait{
    int id;
    int time;

    wait(int a,int b){
        id=a;
        time=b;
    }

    wait(){}
};

struct line{
    int current_id;
    int current_time;
    queue<wait>waiting;
    int totaltime;

    line(){
        totaltime=0;
    }
};

struct can_in
{
    int id;
    int total_time;

    can_in(int a,int b){
        id=a;
        total_time=b;
    }

    can_in(){}
};

bool cmp(can_in &a,can_in &b){
    if(a.total_time==b.total_time){
        return a.id<b.id;
    }
    return a.total_time<b.total_time;
}

queue<wait>out_waiting;
unordered_map<int,int>res;
vector<can_in>vec_in;

int N,M,K,Q;

int t_time;

int main(void){
    ios::sync_with_stdio(false);
    cin>>N>>M>>K>>Q;
    vector<line>in_waiting(N);

    if(K<=N*M){
        for(int i=0;i<K;i++){
            cin>>t_time;
            in_waiting[(i+N)%N].waiting.push(wait(i+1,t_time));
            in_waiting[(i+N)%N].totaltime+=t_time;
        }
    }else{
        for(int i=0;i<N*M;i++){
            cin>>t_time;
            in_waiting[(i+N)%N].waiting.push(wait(i+1,t_time));
            in_waiting[(i+N)%N].totaltime+=t_time;
        }
        for(int i=N*M;i<K;i++){
            cin>>t_time;
            out_waiting.push(wait(i+1,t_time));
        }
    }

    /*开始模拟*/
    for(int i=0;i<N;i++){
        in_waiting[i].current_id=in_waiting[i].waiting.front().id;
        in_waiting[i].current_time=in_waiting[i].waiting.front().time;
        in_waiting[i].waiting.pop();
    }

    for(int i=1;i<=540;i++){
        bool flag=true;
        vec_in.clear();
        for(int j=0;j<N;j++){
            line& temp= in_waiting[j];
            if(temp.totaltime==0)continue;
            flag=false;
            if(--temp.current_time==0){
                res[temp.current_id]=i;
                temp.totaltime--;
                if(i!=540){
                    temp.current_id=temp.waiting.front().id;
                    temp.current_time=temp.waiting.front().time;
                    temp.waiting.pop();
                    vec_in.push_back(can_in(j,temp.waiting.size()));
                }
                
            }else{
                temp.totaltime--;
            }
        }
        if(!out_waiting.empty()){
            sort(vec_in.begin(),vec_in.end(),cmp);
            for(int j=0;j<vec_in.size();j++){
                line& tmp=in_waiting[vec_in[j].id];
                tmp.waiting.push(out_waiting.front());
                tmp.totaltime+=out_waiting.front().time;
                out_waiting.pop();
                if(out_waiting.empty())break;
            }
        }
        
        if(flag) break;
    }

    /*17点后不再接受新服务，但服务到一半的要服务完*/
    for(int i=0;i<N;i++){
        if(in_waiting[i].current_id<=K){
            res[in_waiting[i].current_id]=540+in_waiting[i].current_time;
        }
    }

    
    for(int i=0;i<Q;i++){
        int in;
        cin>>in;
        if(res.count(in)!=0){
            printf("%02d:%02d\n",8+res[in]/60,res[in]%60);
        }else{
            cout<<"Sorry\n";
        }
    }

}

