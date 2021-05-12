/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-10 12:07:45
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sa;
int b;
vector<int>a,c;

void mul(vector<int>& a,int b){
    int t=0;
    for(int i=0;i<a.size()||t!=0;i++){
        if(i<a.size())t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(c.size()>1&&c.back()==0)c.pop_back();
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>sa>>b;
    for(int i=sa.size()-1;i>=0;i--)a.push_back(sa[i]-'0');
    mul(a,b);
    for(int i=c.size()-1;i>=0;i--)cout<<c[i];
}
