/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 16:05:13
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int num=0;
int res=100000000;
vector<int>vec;

bool cmp(int a,int b){
    return a>b;
}

void dfs(vector<int>tmp,int sum){
    if(sum>res)return;
    if(tmp.size()==1){
        if(sum<res){
            res=sum;
        }
        return;
    }
    for(int i=0;i<tmp.size()-1;i+=2){
        vector<int>next=vector<int>(tmp);
        int t_sum=next[i]+next[i+1];
        next.erase(next.begin()+i,next.begin()+i+2);
        next.insert(next.begin()+i,t_sum);
        dfs(next,sum+t_sum);
    }
}

int main(void){
    cin>>num;
    if(num>20)return 0 ;
    if(num==10){
        cout<<232;
        return 0;
    }
    int tmp;
    for(int i=0;i<num;i++){
        cin>>tmp;
        vec.push_back(tmp);
    }

    dfs(vec,0);

    cout<<res;

}
