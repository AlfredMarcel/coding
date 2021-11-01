/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-09-23 09:20:39
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    vector<int>tmp={1,2,3,4,5,6,7,8};
    int l=0,r=tmp.size()-1;
    int box=0;
    while(r>l){
        if(tmp[l]%2==0){
            if(tmp[r]%2==0){
                r--;
            }else{
                box=tmp[r];
                tmp[r]=tmp[l];
                tmp[l]=box;
                r--;
                l++;
            }
        }else{
            if(tmp[r]%2==0){
                r--;
                l++;
            }else{
                l++;
            }
        }
    }
    for(int i:tmp)cout<<i<<" ";
}
