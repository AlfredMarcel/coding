/*
 * @Description: 单调栈
 * @Author: Marcel
 * @Date: 2021-04-08 16:10:32
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;



string removeDuplicateLetters(string s) {
    vector<int>save(26,0),num(26,0);
    stack<char>stk;

    for(int i=0;i<s.size();i++){
        num[s[i]-'a']++;
    }

    for(int i=0;i<s.size();i++){
        num[s[i]-'a']--;
        if(!save[s[i]-'a']){
            while(stk.empty()==false&&stk.top()>s[i]){
            if(num[stk.top()-'a']>0){
                save[stk.top()-'a']=0;
                stk.pop();
            }else break;
        }
        stk.push(s[i]);
        save[s[i]-'a']=1;
        }
        
    }
    string res="";
    while(stk.empty()!=true){
        res=stk.top()+res;
        stk.pop();
    }
    return res;

}

int main(void){
    cout<<removeDuplicateLetters("cbacdcbc");
}
