/*
 * @Description: 快慢指针，类似unique的操作
 * @Author: Marcel
 * @Date: 2021-04-18 21:08:25
 */
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;
/*
int removeDuplicates(vector<int>& nums) {
    if(nums.empty())return 0;
    int slow=0;
    int fast=0;
    while(fast!=nums.size()){
        if(nums[slow]!=nums[fast]){
            slow++;
            nums[slow]=nums[fast];
        }
        fast++;
    }
    return slow+1;
}*/

int removeDuplicates(vector<int>& nums) {
    return unique(nums.begin(),nums.end())-nums.begin();
}

int main(void){
    vector<int>vec={};
    cout<<removeDuplicates(vec);
}
