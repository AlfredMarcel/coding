/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-19 08:49:51
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int res=0;
    int left=0;
    int right=0;
    while(right!=s.size()){
        for(int i=left;i<right;i++){
            if(s[i]==s[right]){
                left=i+1;
                break;
            }
        }
        res=max(res,right-left+1);
        right++;
    }
    return res;
}

int main(void){
    cout<<lengthOfLongestSubstring("abcabcbb");
}
