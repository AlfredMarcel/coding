/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-01 15:56:12
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N=100010;

int M;
int head,e[N],ne[N],idx;

void handleH(int p1){
    e[idx]=p1;
    ne[idx]=head;
    head=idx++;
}

void handleI(int p1,int p2){
    e[idx]=p2;
    ne[idx]=ne[p1-1];
    ne[p1-1]=idx;
    idx++;
}

void handleD(int p1){
    if(p1==0){
        head=ne[head];
    }else{
        ne[p1-1]=ne[ne[p1-1]];
    }
}

void output(){
    int h=head;
    while(h!=-1){
        cout<<e[h]<<" ";
        h=ne[h];
    }
}

int main(void){
    cin.sync_with_stdio(false);
    cin.tie();

    cin>>M;
    char op;
    int p1,p2;

    /*初始化*/
    head=-1;
    idx=0;

    for(int i=0;i<M;i++){
        cin>>op;
        if(op=='H'){
            cin>>p1;
            handleH(p1);
        }else if(op=='I'){
            cin>>p1>>p2;
            handleI(p1,p2);
        }else if(op=='D'){
            cin>>p1;
            handleD(p1);
        }
    }

    output();

}
