#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int>num={1,4,0,-1,-2,-3,-1,-2};

/*正解，单调栈*/
bool find132pattern(vector<int>& nums){
        
    stack<int>TopIsSmall;
    int last_max=INT_MIN;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]<last_max){
            return true;
        }
        while(!(TopIsSmall.empty()) and nums[i]>TopIsSmall.top()){
            last_max=max(last_max,TopIsSmall.top());
            TopIsSmall.pop();
        }
        TopIsSmall.push(nums[i]);
    }
    return false;
}

/*
最初想法，分解步数贪心，是错的
bool find132pattern(vector<int>& nums){
    int step=1;
    int first=0;
    int second=0;
    for(int i=0;i<nums.size();i++){
        if(step==1){
            first=nums[i];
            step++;
            continue;
        }else if(step==2){
            if(nums[i]<=first){
                first=nums[i];
                continue;
            }else{
                second=nums[i];
                step++;
            }
        }else if(step==3){
            if(nums[i]>=second){
                second=nums[i];
                continue;
            }else{
                if(nums[i]>first){
                    step++;
                }
            }
        }
        if(step==4){
            return true;
        }
    }
    return false;
}*/

int main(void){
    cout<<find132pattern(num);
}