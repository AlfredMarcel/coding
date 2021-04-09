/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-09 19:53:15
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {

    vector<int>nums2=vector<int>(nums);
    for(int i=0;i<nums.size();i++){
        nums2.push_back(nums[i]);
    }

    unordered_map<int,int>tab;
    stack<int>stk;

    for(int i=0;i<nums2.size();i++){
        while(!stk.empty()&&nums2[i]>nums2[stk.top()]){
            tab[stk.top()]=nums2[i];
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        tab[stk.top()]=-1;
        stk.pop();
    }

    vector<int>res;
    int length=nums.size();
    for(int i=0;i<length;i++){
        res.push_back(tab[i]);
    }
    return res;

}

vector<int>vec={1,2,1};
int main(void){
    nextGreaterElements(vec);
}

