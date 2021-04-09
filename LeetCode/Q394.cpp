/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-09 14:29:58
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

string decodeString(string s) {
    string res="";
    stack<string>stk;
    for(int i=0;i<s.size();i++){
        if(s[i]==']'){
            string tmp="";
            while(stk.top()!="["){
                tmp=stk.top()+tmp;
                stk.pop();
            }
            stk.pop();
            string tmp_num="";
            while(stk.empty()==false&&stk.top()[0]>='0'&&stk.top()[0]<='9'){
                tmp_num=stk.top()+tmp_num;
                stk.pop();
            }
            string to_push;
            for(int j=0;j<stoi(tmp_num);j++){
                to_push+=tmp;
            }
            stk.push(to_push);
        }
        else{
            stk.push(string(1,s[i]));
        }
    }
    while(stk.empty()!=true){
        res=stk.top()+res;
        stk.pop();
    }
    return res;
}
int main(void){
    cout<<decodeString("3[a]2[bc]");
}
