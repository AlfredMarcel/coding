/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-20 12:44:46
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxArea(vector<int>& height) {
    int left=0;
    int right=height.size()-1;
    int res=0;
    while(right>left){
        if(height[right]>=height[left]){
            res=max(height[left]*(right-left),res);
            left++;
        }
        if(height[right]<height[left]){
            res=max(height[right]*(right-left),res);
            right--;
        }
    }
    return res;
}

int main(void){
    
}
