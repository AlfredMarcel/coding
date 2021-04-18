/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-17 22:27:59
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<cmath>

using namespace std;

int handle(int tmp,int num){
    int res=0;
    for(int i=0;i<num;i++){
        int t=tmp%2;
        if(t==0)res+=(int)pow(2,i);
        tmp/=2;
    }
    return res;
}

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    vector<int>res;
    vector<int>tmp_save;
    int tmp=nums[0];
    tmp_save.push_back(tmp);
    for(int i=1;i<nums.size();i++){
        tmp=tmp^nums[i];
        tmp_save.push_back(tmp);
    }
    for(int i=tmp_save.size()-1;i>=0;i--){
        res.push_back(handle(tmp_save[i],maximumBit));
    }
    return res; 
}




int main(void){
    vector<int>vec={0,1,1,3};
    getMaximumXor(vec,2);
    cout<<"";
}
