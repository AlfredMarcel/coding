/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 11:26:46
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    long res;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            if(j==0&&i==0)res=arr1[i]&arr2[j];
            else res=res^arr1[i]&arr2[j];
        }
    }
    return (int)res;
}

int main(void){
    
}
