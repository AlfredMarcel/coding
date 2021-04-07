/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-06 21:04:30
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int removeDuplicates(vector<int>& nums) {

    int now_num = nums[nums.size()-1];
    int length=0;

    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]==now_num){
            length++;
        }else{
            if(length>2){
                nums.erase(nums.begin()+i+1,nums.begin()+i+length-1);
            }
            now_num=nums[i];
            length=1;
        }
    }
    if(length>2){
        nums.erase(nums.begin(),nums.begin()+length-2);
    }

    return nums.size();
}

vector<int>vec={0,0,1,1,1,1,2,3,3};

int main(void){
    cout<<removeDuplicates(vec);
}
