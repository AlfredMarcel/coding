/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-26 22:29:50
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        stack<int>st;
        stack<int>st2;
        int sum=0;
        bool flag1=true,flag2=true;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[i]<=st.top()){
                st.pop();
                sum++;
            }
            st.push(nums[i]);
            if(sum>=2)flag1=false;
        }
        int sum2=0;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st2.empty()&&nums[i]>=st2.top()){
                st2.pop();
                sum2++;
            }
            st2.push(nums[i]);
            if(sum2>=2)flag2=false;
        }
        return flag1||flag2;
    }
};

int main(void){
    Solution* s=new Solution();
    vector<int>vec={1,2,0,5,7};
    cout<<s->canBeIncreasing(vec);
}
