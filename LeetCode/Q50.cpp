/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-17 10:02:15
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using namespace std;

unordered_map<int,double>cache;

double r_pow(double x,int m){
    if(cache.find(m)!=cache.end())return cache[m];
    if(m==1){
        cache[m]=x;
        return x;
    }
    if(m==-1){
        cache[m]=1/x;
        return 1/x;
    }
    if(m==0){
        cache[m]=1.0;
        return 1.0;
    }
    double d1=r_pow(x,m/2);
    cache[m/2]=d1;
    double d2=r_pow(x,m-m/2);
    cache[m-m/2]=d2;
    return d1*d2;
}

double myPow(double x,int m){
    return r_pow(x,m);
}

int main(void){
    cout<<myPow(2.0,-2);
}
