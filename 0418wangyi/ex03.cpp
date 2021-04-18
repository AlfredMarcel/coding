/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 15:36:43
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N,M;
string input;

int main(void){
    cin>>N>>M;
    cin>>input;
    if(M==1)cout<<stoi(input.substr(0,N/2))*stoi(input.substr(N/2));
    if(M==2){
        cout<<stoi(input.substr(0,N/3))*stoi(input.substr(N/3,N/3))*stoi(input.substr(N/3));
    }
}
