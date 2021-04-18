/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 15:07:52
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long a,b;

int main(void){
    long long sum=0;
    cin>>a>>b;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            sum+=(a-i)*(b-j)*(i+1)*(j+1);
        }
    }
    cout<<sum;
}
