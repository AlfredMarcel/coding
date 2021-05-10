/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-10 11:42:25
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sa,sb;
vector<int>a,b,c;

bool judge(vector<int>& a,vector<int>& b){
    if(a.size()!=b.size())return a.size()>b.size();
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=b[i])return a[i]>b[i];
    }
    return true;
}

void sub(vector<int>& a,vector<int>& b){
    int t=0;
    for(int i=0;i<a.size();i++){
        t=a[i]-t;
        if(i<b.size())t-=b[i];
        c.push_back((t+10)%10);
        if(t<0)t=1; else t=0;
    }
    while(c.size()>1&&c.back()==0)c.pop_back();
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>sa>>sb;
    for(int i=sa.size()-1;i>=0;i--)a.push_back(sa[i]-'0');
    for(int i=sb.size()-1;i>=0;i--)b.push_back(sb[i]-'0');
    /*判断正负*/
    if(judge(a,b)){
        sub(a,b);
        for(int i=c.size()-1;i>=0;i--)cout<<c[i];
    }else{
        sub(b,a);
        cout<<"-";
        for(int i=c.size()-1;i>=0;i--)cout<<c[i];
    }    
    
}
