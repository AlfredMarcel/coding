/*
 * @Description: PAT A 1109
 * @Author: Marcel
 * @Date: 2021-04-01 15:13:03
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

struct student{

    string name;
    int height;

    student(string a,int b){
        name=a;
        height=b;
    }

    student(){}
};

bool cmp(student &a,student &b){
    if(a.height==b.height){
        return a.name<b.name;
    }else{
        return a.height>b.height;
    }
}

int N,K;
vector<student>vec;

int main(void){
    ios::sync_with_stdio(false);
    cin>>N>>K;
    string tmp1;
    int tmp2;
    for(int i=0;i<N;i++){
        cin>>tmp1>>tmp2;
        vec.push_back(student(tmp1,tmp2));
    }

    sort(vec.begin(),vec.end(),cmp);

    vector<student>::iterator it=vec.begin();

    int num=N/K;
    int first=N%K+num;

    string temp_res="";
    temp_res+=it->name;
    it++;
    for(int i=1;i<first;i++){
        if((i+2)%2!=0){
            temp_res=it->name+" "+temp_res;
            it++;
        }else{
            temp_res+=" "+it->name;
            it++;
        }
    }
    cout<<temp_res<<"\n";

    for(int i=0;i<K-1;i++){
        temp_res="";
        temp_res+=it->name;
        it++;
        for(int j=1;j<num;j++){
            if((j+2)%2!=0){
                temp_res=it->name+" "+temp_res;
                it++;
            }else{
                temp_res+=" "+it->name;
                it++;
            }
        }
        cout<<temp_res<<"\n";
    }

    
}

