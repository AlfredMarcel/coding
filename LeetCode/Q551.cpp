/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-08-17 10:53:10
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:
    bool checkRecord(string s) {
        int sum_a=0;
        int sum_l=0;
        for(char tmp:s){
            if(tmp=='A')sum_a++;
            if(tmp=='L')sum_l++;
            else sum_l=0;
            if(sum_a==2||sum_l==3)return false;
        }
        return true;
    }
};

int main(void){
    
}
