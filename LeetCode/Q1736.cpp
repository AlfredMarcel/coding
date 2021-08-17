/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-24 18:36:10
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    string handle(string ss){
        for(int i=0;i<ss.size();i++){
            if(ss[i]=='?'){
                char tmp;
                if(i==0){
                    if(ss[1]>='4'||ss[1]!='?')tmp='1';
                    else tmp='2';
                }
                else if(i==1){
                    if(ss[0]=='2')tmp='3';
                    else tmp='9';
                }else if(i==3)tmp='5';
                else if(i==4)tmp='9';

                ss[i]=tmp;
            }
        }
        return ss;
    }

    string maximumTime(string time) {
        return handle(time);
    }
};

int main(void){
    
}
