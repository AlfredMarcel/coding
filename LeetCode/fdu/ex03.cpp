/*
 * @Description: ex03
 * @Author: Marcel
 * @Date: 2021-07-06 10:06:06
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//从vector<int>输入

//a^a=0 0^b=b 且满足交换律 
int findOne(vector<int>&vec){
    int res=0;
    for(int i:vec)res^=i;
    return res;
}

int main(void){
    vector<int>vec={2,3,1,3,2,4,4,5,8,8,5};
    cout<<findOne(vec);    
}
