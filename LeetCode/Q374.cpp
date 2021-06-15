/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-14 11:09:39
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int guess(int num){
    return 1;
}

int guessNumber(int n) {
    int l=1;
    int r=n;
    int mid;
    int gus;
    while(r-l>=1){
        mid=(l+r)/2;
        gus=guess(mid);
        if(gus==1)l=mid+1;
        else if(gus==-1)r=mid-1;
        else return mid;
    }
    for(int i=l;i<=r;i++){
        if(guess(i)==0)return i;
    }
    return 0;        
}

int main(void){
    
}
