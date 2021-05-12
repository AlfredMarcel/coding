/*
 * @Description: 区间合并
 * @Author: Marcel
 * @Date: 2021-05-12 19:20:37
 */

#include <iostream>
#include <vector>
#include <string>
#include<map>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>>vec;

int main(void){
    ios::sync_with_stdio(false);
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());

    int sum=0;
    pair<int,int>current=vec[0];
    for(int i=1;i<vec.size();i++){
        if(vec[i].second<=current.second)continue;
        else{
            if(vec[i].first<=current.second){
                current.second=vec[i].second;
            }else{
                sum++;
                current=vec[i];
            }
        }
    }
    sum++;

    cout<<sum;
}
