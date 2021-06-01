/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-01 16:43:37
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

stack<int> stk;
int N;

int main(void){
    cin.sync_with_stdio(false);
    cin.tie();

    cin>>N;
    int tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        while(!stk.empty()&&stk.top()>=tmp){
            stk.pop();
        }
        if(stk.empty()){
            cout<<"-1 ";
        }else{
            cout<<stk.top()<<" ";
        }
        stk.push(tmp);
    }
}
