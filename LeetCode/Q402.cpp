/*
 * @Description: 单调栈，但不知道为什么很慢
 * @Author: Marcel
 * @Date: 2021-04-09 15:38:49
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

string removezero(string &t){
    for(int i=0;i<t.size();i++){
        if(t[i]=='0')continue;
        return t.substr(i,t.size()-i);
    }
    return "0";
}

string removeKdigits(string num, int k) {
    stack<char>stk;
    for(int i=0;i<num.size();i++){
        /*破坏单调非递减（大于等于）*/
        while(stk.empty()!=true&&stk.top()>num[i]){
            if(k==0)break;
            stk.pop();
            k--;
        }
        stk.push(num[i]);
    }

    /*k不等于0，说明移除名额没用完，此时栈是非递减的，所以pop就可以*/
    while(k!=0){
        stk.pop();
        k--;
    }

    string res="";
    while(stk.empty()!=true){
        res=stk.top()+res;
        stk.pop();
    }
    if(res=="")return "0";
    return removezero(res);
}

int main(void){
    cout<<removeKdigits("10200",1);
}
