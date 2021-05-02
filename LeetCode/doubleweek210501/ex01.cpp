/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-01 22:43:02
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string replaceDigits(string s) {
    string res="";
    for(int i=0;i<s.size();i++){
        if((i+2)%2==0)res+=s[i];
        else{
            res+=s[i]-'0'+res.back();
        }
    }
    return res;
}

int main(void){
    
}
