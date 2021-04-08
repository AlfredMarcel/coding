/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-08 22:52:59
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int>::iterator it1=pushed.begin();
    vector<int>::iterator it2=popped.begin();
    stack<int>tmp;
    bool res;

    int current;

    while(it2!=popped.end()){
        current=*(it2);
        if(tmp.empty()||tmp.top()!=current){
            bool tmp_flag=false;
            while(it1!=pushed.end()){
                tmp.push(*(it1));
                it1++;
                if(*(it1-1)==current){
                    tmp_flag=true;
                    break;
                }
            }
            if(tmp_flag)tmp.pop();
            it2++;
        }else{
            tmp.pop();
            it2++;
        }

    }

    if(tmp.empty())return true;
    return false;
}

int main(void){
    
}

