/*
 * @Description: PAT A1065
 * @Author: Marcel
 * @Date: 2021-03-25 14:59:19
 */

/*longlong 判溢出*/

#include <iostream>
#include <vector>
#include <string>
#include<stdio.h>

using namespace std;

int T;
long long t1,t2,t3,res; 

int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        scanf("%lld %lld %lld",&t1,&t2,&t3);
        res=t1+t2;
        //正溢出
        if(t1>0&&t2>0&&res<0){
            cout<<"Case #"<<i+1<<": true\n";
            continue;
        }
        //负溢出
        if(t1<0&&t2<0&&res>=0){
            cout<<"Case #"<<i+1<<": false\n";
            continue;
        }
        if(t1+t2>t3){
            cout<<"Case #"<<i+1<<": true\n";
        }else{
            cout<<"Case #"<<i+1<<": false\n";         
        }
        
        
    }

}



