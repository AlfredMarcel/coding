/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-12 11:32:24
 */
#include <iostream>
#include <vector>
#include <string>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;


bool cmp(int a,int b){
    string tmp1=to_string(a);
    string tmp2=to_string(b);
    string t1=tmp1+tmp2;
    string t2=tmp2+tmp1;
    return t1>t2;
}

string largestNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end(),cmp);
    string res="";
    for(int i=0;i<nums.size();i++){
        res+=to_string(nums[i]);
    }
    if(res[0]=='0')return "0";
    return res;
}

vector<int>vec={94329,9432};

int main(void){
    cout<<largestNumber(vec);
}

