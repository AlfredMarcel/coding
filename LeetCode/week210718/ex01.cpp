/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-18 10:21:22
 */

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {

    bool st[30];

public:
    int canBeTypedWords(string text, string brokenLetters) {

        int res=0;

        for(char tt:brokenLetters){
            st[tt-'a']=true;
        }

        bool flag=true;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){res+=flag;flag=true;}
            else{
                if(flag){
                    if(st[text[i]-'a'])flag=false;
                }
            }
        }
        if(flag)res++;

        return res;
    }
};

int main(void){
    
}
