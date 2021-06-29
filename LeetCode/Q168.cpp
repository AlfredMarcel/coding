/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-29 11:42:08
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber>0){
            char tmp=(--columnNumber)%26+'A';
            res=tmp+res;
            columnNumber/=26;
        }
        return res;
    }
};

int main(void){
    
}
