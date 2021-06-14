/*
 * @Description: 匈牙利算法
 * @Author: Marcel
 * @Date: 2021-06-13 12:31:46
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>

using namespace std;

const int N=510;

/*男方的目标*/
vector<int> lst[N];
/*女方的匹配对象*/
int match[N];
/*标记女方以访问数组*/
bool st[N];

int n1,n2,m;

bool find(int idx){
    for(int i=0;i<lst[idx].size();i++){
        int j=lst[idx][i];
        if(!st[j]){
            st[j]=true;
            if(match[j]==0||find(match[j])){
                match[j]=idx;
                return true;
            }
        }
    }
    return false;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n1>>n2>>m;
    int v1,v2;
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        lst[v1].push_back(v2);
    }

    int res=0;

    for(int i=1;i<=n1;i++){
        memset(st,false,sizeof st);
        if(find(i))res++;
    }
    cout<<res;
}
