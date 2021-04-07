/*
 * @Description: PAT A1063
 * @Author: Marcel
 * @Date: 2021-03-27 15:32:48
 */

#include <iostream>
#include <vector>
#include <string>
#include<set>
#include<iomanip>
#include<cstdio>

using namespace std;

vector<set<int>>vec;
int N,M,M_temp;
int K;
int a,b;
int length_small,length_big,same_num;
set<int>small,big;

int main(void){
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
        set<int> temp;
        cin>>M;
        for(int j=0;j<M;j++){
            cin>>M_temp;
            temp.insert(M_temp);
        }
        vec.push_back(temp);
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>a>>b;
        a-=1;
        b-=1;
        if(vec[a].size()<vec[b].size()){
            small=vec[a];
            big=vec[b];
        }else{
            small=vec[b];
            big=vec[a];
        }
        length_small=small.size();
        length_big=big.size();
        same_num=0;
        //数小的set就行了
        set<int>::iterator it_s=small.begin();
        set<int>::iterator it_b=big.begin();
        while(it_s!=small.end() && it_b!=big.end()){
            if(*(it_s)==*(it_b)){
                same_num++;
                it_s++;
                it_b++;
            }else if(*(it_s)<*(it_b)){
                it_s++;
            }else if(*(it_s)>*(it_b)){
                it_b++;
            }
        }
        printf("%.1f%\n",same_num*1.0/(length_small+length_big-same_num)*100);

    }
}

