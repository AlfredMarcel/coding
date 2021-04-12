/*
 * @Description: lc 264 
 * @Author: Marcel
 * @Date: 2021-04-11 16:55:50
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<set>

using namespace std;


int nthUglyNumber(int n){
    set<long>ugly;
    ugly.insert(1);
    set<long>::iterator it=ugly.begin();
    for(int i=0;i<n;i++){
        ugly.insert(*(it)*2);
        ugly.insert(*(it)*3);
        ugly.insert(*(it)*5);
        it++;
    }
    it--;
    return *(it); 
}

int main(void){
    cout<<nthUglyNumber(1);
}
