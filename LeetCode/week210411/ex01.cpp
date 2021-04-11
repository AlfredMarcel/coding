/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-11 10:29:24
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arraySign(vector<int>& nums) {
    int res=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            res=0;
            break;
        }
        if(nums[i]<0)res*=-1;
    }
    return res;
}

int main(void){
    
}
