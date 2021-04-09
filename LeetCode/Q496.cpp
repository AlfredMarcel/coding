/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-09 19:07:15
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>
#include<unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
    unordered_map<int,int>tab;
    stack<int>stk;

    for(int i=0;i<nums2.size();i++){
        while(!stk.empty()&&stk.top()<nums2[i]){
            tab[stk.top()]=nums2[i];
            stk.pop();
        }
        stk.push(nums2[i]);
    }
    while(!stk.empty()){
        tab[stk.top()]=-1;
        stk.pop();
    }

    vector<int>res;
    for(int i=0;i<nums1.size();i++){
        res.push_back(tab[nums1[i]]);
    }
    return res;
    
}

int main(void){
    
}

