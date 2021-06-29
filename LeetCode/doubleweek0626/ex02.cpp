/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-26 22:49:05
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int ss=part.size();
        int idx=s.find(part);
        while(idx!=-1){
            s.erase(s.begin()+idx,s.begin()+idx+ss);
            idx=s.find(part);
        }
        return s;
    }
};

int main(void){
    
}
