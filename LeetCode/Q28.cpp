/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-20 12:28:34
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    if(needle.size()==0)return 0;
    if(haystack.size()==0)return -1;
    int index=0;
    int left=0;
    int right=0;

    while(right!=needle.size()){
        if(left==haystack.size())return -1;
        if(haystack[left]==needle[right]){
            left++;
            right++;
        }else{
            index++;
            left=index;
            right=0;
        }
    }
    return index;
}

int main(void){
    cout<<strStr("abababa","babac");
}
