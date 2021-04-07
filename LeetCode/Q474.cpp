/*
 * @Description: leetcode Q474  WA
 * @Author: Marcel
 * @Date: 2021-04-05 13:43:51
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int count(string &s , char c){
    int num=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==c)num++;
    }
    return num;
}

bool cmp0(string &s1,string &s2){
    if(s1.size()==s2.size()){
        return count(s1,'0')>count(s2,'0');
    }
    return s1.size()<s2.size();
}


bool cmp1(string &s1,string &s2){
    if(s1.size()==s2.size()){
        return count(s1,'1')>count(s2,'1');
    }
    return s1.size()<s2.size();
}

int findMaxForm(vector<string>& strs, int m, int n) {
    if(m>n){
        sort(strs.begin(),strs.end(),cmp0);
    }else{
        sort(strs.begin(),strs.end(),cmp1);
    }

    int free=m+n;
    int free_m=m;
    int free_n=n;
    int res=0;
    for(int i=0;i<strs.size();i++){
        if(strs[i].size()>free)break;
        if(free_m>=count(strs[i],'0')&&free_n>=count(strs[i],'1')){
            free_m-=count(strs[i],'0');
            free_n-=count(strs[i],'1');
            free-=(count(strs[i],'0')+count(strs[i],'1'));
            res++;
        }
    }
    return res;
}

vector<string>vec ={"10","0001","111001","1","0"};

int main(void){
    cout<<findMaxForm(vec,5,3);
    
}

