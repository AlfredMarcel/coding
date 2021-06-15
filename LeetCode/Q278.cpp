/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-13 11:23:46
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBadVersion(int ver){
    return true;
}

int firstBadVersion(int n) {
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(isBadVersion(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}

int main(void){
    
}
