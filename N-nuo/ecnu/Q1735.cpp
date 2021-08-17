/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-10 19:59:08
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(void){
    int n;
    int sum=0;
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    string tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        for(char tt:tmp){
            if(tt=='J'||tt=='Q'||tt=='K'){
                sum+=tt-'I';
            }else if(tt=='A')sum+=4;
        }
    }
    cout<<sum;
}
