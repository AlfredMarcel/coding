/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-19 18:53:04
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
string tmp;

int main(void){
    cin>>n;
    cin>>tmp;
    int res=0;
    for(int i=0;i<tmp.size();i++){
        res+=(tmp[i]-'A');
    }
    if(res*2<n)cout<<"A";
    else if(res*2==n)cout<<"T";
    else cout<<"B";
    
}
