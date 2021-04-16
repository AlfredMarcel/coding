/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-16 14:30:20
 */
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<string,int>cache;

bool cmp(string s1,string s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}

bool r_judge(string s1,string s2){
    if(!cmp(s1,s2))return false;
    if(s1==s2)return true;
    if(cache.find(s1+s2)!=cache.end()){
        if(cache[s1+s2]==1)return true;
        if(cache[s1+s2]==-1)reutrn false; 
    }
    for(int i=1;i<s1.size();i++){
        if((r_judge(s1.substr(0,i),s2.substr(0,i))&&r_judge(s1.substr(i),s2.substr(i)))||
           (r_judge(s1.substr(0,i),s2.substr(s2.size()-i,i))&&r_judge(s1.substr(i),s2.substr(0,s2.size()-i)))
        ){
            cache[s1+s2]=1;
            return true;
        }
    }
    cache[s1+s2]=-1;
    return false;
}

bool isScramble(string s1, string s2) {
    return r_judge(s1,s2);
}

int main(void){
    
}
