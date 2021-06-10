/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-09 10:31:28
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

const int L=100010;

int trie[L][26];
int cnt[L];
int idx=0;

void insert(string tmp){
    int p=0;
    for(int i=0;i<tmp.size();i++){
        if(trie[p][tmp[i]-'a']==0)trie[p][tmp[i]-'a']=++idx;
        p=trie[p][tmp[i]-'a'];
    }
    cnt[p]++;
}

int query(string tmp){
    int p=0;
    for(int i=0;i<tmp.size();i++){
        if(trie[p][tmp[i]-'a']==0)return 0;
        p=trie[p][tmp[i]-'a'];
    }
    return cnt[p];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>N;
    char op;
    string tmp;
    for(int i=0;i<N;i++){
        cin>>op>>tmp;
        if(op=='I')insert(tmp);
        else if(op=='Q')cout<<query(tmp)<<"\n";
    }
}
