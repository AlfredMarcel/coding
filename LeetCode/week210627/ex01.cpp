/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-27 10:27:48
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int length=nums.size();
        sort(nums.begin(),nums.end());
        return nums[length-1]*nums[length-2]-nums[1]*nums[0];
    }
};

int main(void){
    
}
