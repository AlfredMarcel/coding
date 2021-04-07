/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-06 21:22:27
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

bool isValid(string s){
    stack<char>tmp;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')tmp.push(s[i]);
        else{
            if(tmp.empty())return false;
            if(s[i]==']'){
            
            if(tmp.top()!='[')return false;
            tmp.pop();
            }
            if(s[i]==')'){
                if(tmp.top()!='(')return false;
                tmp.pop();
            }
            if(s[i]=='}'){
                if(tmp.top()!='{')return false;
                tmp.pop();
            }
        }
        
    }
    if(tmp.size()!=0)return false;
    return true;
}

int main(void){
    cout<<isValid("(");
}

