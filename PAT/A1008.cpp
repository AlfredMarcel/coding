#include<iostream>
#include<vector>

using namespace std;

vector<int>lst;

int main(){

    int temp;
    int cur=0;
    int res=0;
    while(cin>>temp){
        lst.push_back(temp);
    }
    for(int i=1;i<lst.size();i++){
        if(lst[i]<cur){
            res+=4*(cur-lst[i])+5;
        }else{
            res+=6*(lst[i]-cur)+5;
        }
        cur=lst[i];
    }
    cout<<res;

}