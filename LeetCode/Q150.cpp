/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-08 15:08:03
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

bool judgeCal(string &t){
    if((t=="+")||(t=="-")||(t=="*")||(t=="/"))return true;
    return false;
}

int evalRPN(vector<string>& tokens) {
    stack<int>num;

    for(int i=0;i<tokens.size();i++){
        if(!judgeCal(tokens[i]))num.push(stoi(tokens[i]));
        else{
            int num1,num2;
            num2=num.top();
            num.pop();
            num1=num.top();
            num.pop();
            string cal_flag=tokens[i];
            if(cal_flag=="+")num.push(num1+num2);
            if(cal_flag=="-")num.push(num1-num2);
            if(cal_flag=="*")num.push(num1*num2);
            if(cal_flag=="/")num.push(num1/num2);
        }
    }
    return num.top();
}

int main(void){
    
}
