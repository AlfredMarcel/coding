/*
 * @Description: 离散化
 * @Author: Marcel
 * @Date: 2021-05-12 18:11:59
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<pair<int,int>>vec;
vector<pair<int,int>>query;
unordered_map<int,int>tab;
int n,m;
int q[300010];
int s[300010];

int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec.push_back({a,b});
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        query.push_back({a,b});
        vec.push_back({a,0});
        vec.push_back({b,0});
    }
    vector<pair<int,int>>vecb(vec);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    /*使用哈希，进行离散化*/
    /*就是一个下标映射的过程*/
    for(int i=0;i<vec.size();i++){
        tab[vec[i].first]=i;
    }

    for(int i=0;i<vecb.size();i++){
        q[tab[vecb[i].first]]+=vecb[i].second;
    }
    for(int i=1;i<=vecb.size();i++){
        s[i]=s[i-1]+q[i-1];
    }
    
    for(int i=0;i<query.size();i++){
        cout<<s[tab[query[i].second]+1]-s[tab[query[i].first]]<<"\n";
    }

}
