/*
 * @Description: PAT A 1026
 * @Author: Marcel
 * @Date: 2021-04-02 20:22:50
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include<algorithm>

using namespace std;

struct man{
    int arrive_time;
    int play_time;

    man(int a,int b){
        arrive_time=a;
        play_time=b;
    }

    man(){}

};

struct table{
    int time;
    int vip;
    int num;


    table(){
        time=0;
        vip=0;
        num=0;
    }
};

int handletime(string t){
    return (stoi(t.substr(0,2))-8)*3600+stoi(t.substr(3,2))*60+stoi(t.substr(6,2));
}

bool cmp(man &a, man &b){
    return a.arrive_time<b.arrive_time;
}

void foutput(int a ,int b){
    int c;
    if(a==b)c=0;
    else c= (b-a+60)%60==0? (b-a)/60:(b-a)/60+1;
    int h1=a/3600+8;
    int m1=(a%3600)/60;
    int s1=a%60;
    int h2=b/3600+8;
    int m2=(b%3600)/60;
    int s2=b%60;

    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",h1,m1,s1,h2,m2,s2,c);
}

int N;
string tmp1;
int tmp2,vip_tmp;
int K,M,viptableid;

vector<man>vnot_vip;
vector<man>vvip;
queue<man>not_vip;
queue<man>vip;

vector<table>tables;

int main(void){
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp1>>tmp2>>vip_tmp;
        if(vip_tmp==1){
            vvip.push_back(man(handletime(tmp1),tmp2));
        }else{
            vnot_vip.push_back(man(handletime(tmp1),tmp2));
        }
    }

    cin>>K>>M;
    for(int i=0;i<K;i++){
        tables.push_back(table());
    }
    for(int i=0;i<M;i++){
        cin>>viptableid;
        tables[viptableid-1].vip=1;
    }

    sort(vvip.begin(),vvip.end(),cmp);
    sort(vnot_vip.begin(),vnot_vip.end(),cmp);

    for(int i=0;i<vvip.size();i++){
        vip.push(vvip[i]);
    }
    for(int i=0;i<vnot_vip.size();i++){
        not_vip.push(vnot_vip[i]);
    }

    for(int i=0;i<46800;i++){
        if(vip.size()==0&&not_vip.size()==0){break;}
        

        for(int j=0;j<tables.size();j++){
            man tempvip;
            man tempnvip;
            if(vip.size()==0){
                tempvip=man(46801,0);
            }else{
                tempvip=vip.front();
            }
            if(not_vip.size()==0){
                tempnvip=man(46801,0);
            }else{
                tempnvip=not_vip.front();
            }
            if(tables[j].time==0){
                if(tempvip.arrive_time<=i&&tempnvip.arrive_time<=i){
                    if(tables[j].vip==1){
                        tables[j].num++;
                        tables[j].time+=vip.front().play_time*60-1;
                        foutput(vip.front().arrive_time,i);
                        vip.pop();
                    }else{
                        if(tempvip.arrive_time<tempnvip.arrive_time){
                            tables[j].num++;
                            tables[j].time+=vip.front().play_time*60-1;
                            foutput(vip.front().arrive_time,i);
                            vip.pop();
                        }else{
                            tables[j].num++;
                            tables[j].time+=not_vip.front().play_time*60-1;
                            foutput(not_vip.front().arrive_time,i);
                            not_vip.pop();
                        }
                    }
                }else if(tempvip.arrive_time<=i){
                    tables[j].num++;
                    tables[j].time+=vip.front().play_time*60-1;
                    foutput(vip.front().arrive_time,i);
                    vip.pop();
                }else if(tempnvip.arrive_time<=i){
                    tables[j].num++;
                    tables[j].time+=not_vip.front().play_time*60-1;
                    foutput(not_vip.front().arrive_time,i);
                    not_vip.pop();
                }
            }else{
                tables[j].time--;
            }
        }
    }

    string res;
    for(int i=0;i<tables.size();i++){
        res+=to_string(tables[i].num)+" ";
    }
    cout<<res.substr(0,res.length()-1);
}

