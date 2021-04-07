/*
 * @Description: leetcode 210404 周赛 第一题
 * @Author: Marcel
 * @Date: 2021-04-04 13:26:07
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string truncateSentence(string s, int k) {
    string res="";
    int num=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            num++;
            if(num==k)break;
        }
        res+=s[i];
    }
    return res;
}

int main(void){
    cout<<truncateSentence("a b c d e",4);
    
}

