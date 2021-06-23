/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-23 00:58:06
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        while(n>0){
            sum+=n&1;
            n=n>>1;
        }
        return sum;      
    }
};

int main(void){
    
}
