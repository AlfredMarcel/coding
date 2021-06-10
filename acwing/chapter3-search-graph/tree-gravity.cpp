/*
 * @Description: Q846
 * @Author: Marcel
 * @Date: 2021-06-10 16:10:48
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


const int N=100010;

int n;
vector<int> tab[N];
bool st[N];
int res=100010;

int dfs(int root){
    st[root]=true;
    int max1=0,sum=1;
    for(int i=0;i<tab[root].size();i++){
        int j=tab[root][i];
        if(!st[j]){
            int tmp=dfs(j);
            max1=max(max1,tmp);
            sum+=tmp;
        }
    }
    max1=max(max1,n-sum);
    res=min(res,max1);

    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    int v1,v2;
    for(int i=0;i<n-1;i++){
        cin>>v1>>v2;
        tab[v1].push_back(v2);
        tab[v2].push_back(v1);
    }

    dfs(1);

    cout<<res;
}
