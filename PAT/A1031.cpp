/*
 * @Description: PAT A1031
 * @Author: Marcel
 * @Date: 2021-04-01 14:57:18
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

string input;
int N;
int k;

int main(void){
    ios::sync_with_stdio(false);
    cin>>input;
    N=input.length();
    k=min((N+2)/3,(N-1)/2);
    string tmp;
    for(int i=0;i<k-1;i++){
        tmp="";
        tmp+=input[i];
        for(int j=0;j<N-2*k;j++){
            tmp+=" ";
        }
        tmp+=input[N-1-i];
        cout<<tmp<<"\n";
    }
    cout<<input.substr(k-1,N-2*k+2);
    

}
