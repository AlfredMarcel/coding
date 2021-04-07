/*
 * @Description: leetcode 1819 unfinished
 * @Author: Marcel
 * @Date: 2021-04-04 14:03:02
 */

#include <iostream>
#include <vector>
#include <string>
#include<set>

using namespace std;

int countDifferentSubsequenceGCDs(vector<int>& nums) {
    set<int> tmp;
    set<int> res;
    for(int i=0;i<nums.size();i++){
        tmp.insert(nums[i]);
    }
    set<int>::iterator it=tmp.begin();
    vector<int>snum;
    for(;it!=tmp.end();it++){
        snum.push_back(*it);
    }

    

}

int main(void){
    
}

