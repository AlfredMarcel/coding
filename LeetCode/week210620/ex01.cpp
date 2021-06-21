/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-20 10:24:51
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string largestOddNumber(string num) {
    int res=num.size();
    for(int i=num.size()-1;i>=0;i--){
        if(num[i]=='1'||num[i]=='3'||num[i]=='5'||num[i]=='7'||num[i]=='9')break;
        else res--;
    }
    return num.substr(0,res);
}

int main(void){
    
}
