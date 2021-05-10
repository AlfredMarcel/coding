/*
 * @Description: 高精度加法
 * @Author: Marcel
 * @Date: 2021-05-10 11:22:52
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>a,b,c;
string sa,sb;

void add(vector<int>& a,vector<int>& b){
    if(a.size()<b.size())return add(b,a);

    int t=0;
    for(int i=0;i<a.size();i++){
        t+=a[i];
        if(i<b.size())t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t!=0)c.push_back(t);
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>sa>>sb;
    for(int i=sa.size()-1;i>=0;i--)a.push_back(sa[i]-'0');
    for(int i=sb.size()-1;i>=0;i--)b.push_back(sb[i]-'0');
    add(a,b);
    for(int i=c.size()-1;i>=0;i--)cout<<c[i];

}

