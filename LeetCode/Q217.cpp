/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-17 10:40:31
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return unique(nums.begin(),nums.end())!=nums.end();
}

int main(void){
    
}
