/*
 * @Description: 不优化必TLE
 * @Author: Marcel
 * @Date: 2021-04-11 11:18:04
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<cmath>

using namespace std;

class MKAverage {

    vector<int>vec;
    int mm;
    int kk;

public:
    MKAverage(int m, int k) {
        vec={};
        mm=m;
        kk=k;
    }
    
    void addElement(int num) {
        vec.push_back(num);
    }
    
    int calculateMKAverage() {
        if(vec.size()<mm)return -1;
        vector<int>tmp;
        for(int i=0;i<mm;i++){
            tmp.push_back(vec[vec.size()-i-1]);
        }
        sort(tmp.begin(),tmp.end());
        int sum=0;
        int k=kk;
        int n=tmp.size()-k*2;
        for(;k<=n;k++){
            sum+=tmp[k];
        }
        return sum/n;
    }
};

int main(void){
    
    MKAverage a(6,1);
    a.addElement(3);
    a.addElement(1);
    a.addElement(12);
    a.addElement(5);
    a.addElement(3);
    a.addElement(4);
    a.calculateMKAverage();

}
