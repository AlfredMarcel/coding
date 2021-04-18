/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 10:29:16
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>vec(26,0);

bool checkIfPangram(string sentence) {
    bool res=true;
    for(char s:sentence){
        vec[s-'a']=1;
    }
    for(int i:vec){
        if(i==0)return false;
    }
    return res;
}

int main(void){
    
}
