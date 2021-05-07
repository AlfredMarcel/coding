/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-03 09:10:23
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int reverse(int x) {
    string tmp=to_string(x);
    if(tmp[0]=='-'){
        std::reverse(tmp.begin()+1,tmp.end());
        if(tmp.substr(1).size()>=10&&tmp.substr(1)>"2147483648")return 0;
        else return stoi(tmp);
    }else{
        std::reverse(tmp.begin(),tmp.end());
        if(tmp.size()>=10&&tmp>"2147483647")return 0;
        else return stoi(tmp);
    }
}

int main(void){
    cout<<reverse(-1234411111);
}
