/*
 * @Description: 浮点数二分
 * @Author: Marcel
 * @Date: 2021-05-07 22:52:12
 */

#include <iostream>
#include <vector>
#include <string>
#include<cmath>
#include<iomanip>

using namespace std;

double eps=1e-8;
double n,mid;
double l=-10000;
double r=10000;

int main(void){
    ios::sync_with_stdio("false");
    cin>>n;
    while(r-l>eps){
        mid=(l+r)/2;
        if(pow(mid,3)<n)l=mid;
        else r=mid;
    }
    printf("%.6f",l);
}
