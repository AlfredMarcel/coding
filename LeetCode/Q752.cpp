/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-25 00:24:37
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
    queue<string>ext;
    unordered_map<string,bool>st;
    unordered_map<string,int>dis;

public:
    char handle_up(char c){
        if(c=='9')return '0';
        else return c+1;
    }

    char handle_down(char c){
        if(c=='0')return '9';
        else return c-1;
    }

    int openLock(vector<string>& deadends, string target) {
        for(string tmp:deadends)st[tmp]=true;
        if(st["0000"])return -1;

        st["0000"]=true;
        ext.push("0000");
        while(!ext.empty()){
            string hh=ext.front();
            ext.pop();
            if(hh==target)return dis[hh];

            for(int i=0;i<=3;i++){
                string tmp_ext=hh;
                for(int j=0;j<=1;j++){
                    if(j==0)tmp_ext[i]=handle_up(hh[i]);
                    else tmp_ext[i]=handle_down(hh[i]);
                
                    if(st[tmp_ext])continue;
                    else{
                        ext.push(tmp_ext);
                        st[tmp_ext]=true;
                        dis[tmp_ext]=dis[hh]+1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(void){
    Solution* s=new Solution();
    vector<string>vec={"0201","0101","0102","1212","2002"};
    string t="0202";
    cout<<s->openLock(vec,t);
}
