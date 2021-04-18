/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 11:39:52
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    long res;
    long tmp=arr2[0];
    for(int i=1;i<arr2.size();i++){
        tmp=tmp^arr2[i];
    }
    long tmp2=arr1[0];
    for(int i=1;i<arr1.size();i++){
        tmp2=tmp2^arr1[i];
    }
    return (int)tmp&tmp2;
}

int main(void){
    
}
