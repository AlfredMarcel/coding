/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-06 10:41:05
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int reductionOperations(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int res=0;
    int sum=0;
    int cur=-1;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]!=cur){
            cur=nums[i];
            res+=sum;
            sum++;
        }else{
            sum++;
        }
    }
    return res;
}

int main(void){
    
}
