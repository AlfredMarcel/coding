/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-06 10:48:38
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minFlips(string s) {
    while(s.front()!=s.back()){
        char tmp=s.front();
        s.push_back(tmp);
        s=s.substr(1);
    }
    int res=0;
    for(int i=1;i<s.size();i++){
        res+=(s[i]-'0')^(s[i-1]-'0');
    }
    return res;
}

int main(void){
    
}
