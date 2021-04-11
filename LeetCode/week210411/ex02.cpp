/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-11 10:33:31
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findTheWinner(int n, int k) {
    vector<int>vec;
    for(int i=1;i<=n;i++)vec.push_back(i);

    int num=n;
    int index=0;
    while(num>1){
        index=(index+k-1)%num;
        vec.erase(vec.begin()+index,vec.begin()+index+1);
        num--;
    }
    return vec[0];
}

int main(void){
    cout<<findTheWinner(6,5);
}
