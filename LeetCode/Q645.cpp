/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-04 11:53:11
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using namespace std;

class Solution {
    unordered_map<int,int>map;
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int a,b;
        for(int i=0;i<nums.size();i++){
            if(!map[nums[i]])map[nums[i]]++;
            else a=nums[i];
        }
        for(int i=1;i<=nums.size();i++){
            if(map.find(i)==map.end()){
                b=i;
                break;
            }
        }
        return {a,b};
    }
};

int main(void){
    vector<int>vec={1,2,2,4};
    Solution *s=new Solution();
    s->findErrorNums(vec);
}
