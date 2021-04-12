/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-12 12:16:06
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cmp(string &a,string &b){
    return (a+b)>(b+a);
}

string largestNumber(vector<int>& nums){
    vector<string>tmps;
    for(int t:nums)tmps.push_back(to_string(t));
    sort(tmps.begin(),tmps.end(),cmp);
    string res="";
    for(string tt:tmps)res+=tt;
    return res;
}

int main(void){
    
}
