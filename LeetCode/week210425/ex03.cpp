/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-25 10:28:04
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>
#include<algorithm>

using namespace std;

int longestBeautifulSubstring(string word) {
    int res=0;
    stack<char>stk;
    for(char c:word){
        if(stk.empty()){
            if(c=='a')stk.push(c);
            continue;
        }
        if(!stk.empty()&&c>=stk.top()){
            if(c==stk.top()||c=='e'&&stk.top()=='a'||c=='i'&&stk.top()=='e'||c=='o'&&stk.top()=='i'||c=='u'&&stk.top()=='o')stk.push(c);
            else{
                while(!stk.empty()){
                stk.pop();
                }
            }
        }else{
            if(stk.top()=='u')res=max(res,(int)stk.size());
            while(!stk.empty()){
                stk.pop();
            }
            if(c=='a')stk.push(c);
        }
    }
    if(!stk.empty())if(stk.top()=='u')res=max(res,(int)stk.size());
    return res;
}

int main(void){
    cout<<longestBeautifulSubstring("eauoiouieaaoueiuaieoeauoiaueoiaeoiuieuaoiaeouiaueo");
}
