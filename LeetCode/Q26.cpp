/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 11:51:23
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    vector<int>::iterator it=nums.begin();
    int tmp=*it;
    it++;
    while(it!=nums.end()){
        if(*it!=tmp){
            tmp=*it;
            it++;
        }
        else nums.erase(it);
    }
    return nums.size();
}

int main(void){
    vector<int>vec={1,1,1,1};
    removeDuplicates(vec);
}
