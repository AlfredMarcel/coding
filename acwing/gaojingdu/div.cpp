/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-10 12:21:13
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

vector<int>a,c;
int b;
string sa;

void div(vector<int>& a,int b,int& r){
    for(int i=a.size()-1;i>=0;i--){
        r=r*10+a[i];
        c.push_back(r/b);
        r%=b;
    }
    reverse(c.begin(),c.end());
    while(c.size()>1&&c.back()==0)c.pop_back();
}

int main(void){
    cin>>sa>>b;
    int r=0;
    for(int i=sa.size()-1;i>=0;i--)a.push_back(sa[i]-'0');
    div(a,b,r);
    for(int i=c.size()-1;i>=0;i--)cout<<c[i];
    cout<<"\n"<<r;

}
