/*
 * @Description: 最大异或对
 * @Author: Marcel
 * @Date: 2021-06-09 11:18:02
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

/*转成二进制字符序列，倒序*/
string handle(int a){
    string res="";
    while(a){
        res.push_back(a%2+'0');
    }
    return res;
}

void insert(string tmp){
    int p;
    for(int i=0;i<tmp.size();i++){
        int u=tmp[i]-'0';
        if(!trie[p][u])trie[p][u]=++idx;
        p=trie[p][u];
    }
}

const int N=100010;

int trie[N][2];
int idx=0;

int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    int tmp;
    vector<string>box;
    for(int i=0;i<n;i++){
        cin>>tmp;
        string st=handle(tmp);
        insert(st);
        box.push_back(st);
    }

    int res=0;
    for(int i=0;i<box.size();i++){
        res=max(cal_xor(box[i]));
    }
    cout<<res;
}

