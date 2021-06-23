/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-22 00:04:14
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include<unordered_set>

using namespace std;

class Solution {
    string ss;
    bool st[10];
    unordered_set<string>res;
    int length;
public:
    void dfs(int num,string tmp){
        if(num==length){
            res.insert(tmp);
            return;
        }
        for(int i=0;i<ss.size();i++){
            if(!st[i]){
                st[i]=true;
                dfs(num+1,tmp+ss[i]);
                st[i]=false;
            }
        }
    }

    vector<string> permutation(string s) {
        ss=s;
        length=s.size();
        memset(st,0,sizeof st);
        dfs(0,"");
        vector<string>vres;
        for(auto i=res.begin();i!=res.end();i++)vres.push_back(*i);
        return vres;
    }
};

int main(void){
    
}
