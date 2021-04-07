/*
 * @Description: PAT A1061
 * @Author: Marcel
 * @Date: 2021-03-31 14:49:34
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

string tmp1,tmp2;
vector<string>vec={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int fun(char &a){
    if(a<='9'){
        return a-48;
    }else{
        return a-55;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>tmp1;
    cin>>tmp2;
    char day=64;
    char minute=47;
    char second;
    int leng=min(tmp1.length(),tmp2.length());
    for(int i=0;i<leng;i++){
        if(tmp1[i]==tmp2[i]&&day==64){
            if(tmp1[i]>='A'&&tmp1[i]<='G'){
                day=tmp1[i];
            }else{
                continue;
            }
        }else if(tmp1[i]==tmp2[i]&&minute==47){
            if((tmp1[i]>='0'&&tmp1[i]<='9')||(tmp1[i]>='A'&&tmp1[i]<='N')){
                minute=tmp1[i];
            }
        }
        if(day!=64&&minute!=47){
            break;
        }
                       
    }
    cin>>tmp1>>tmp2;
    leng=min(tmp1.length(),tmp2.length());
    for(int i=0;i<leng;i++){
        if(tmp1[i]==tmp2[i]&&((tmp1[i]>='A'&&tmp1[i]<='Z')||(tmp1[i]>='a'&&tmp1[i]<='z'))){
            second=i;
            break;
        }
    }

    printf("%s %02d:%02d",vec[day-65].c_str(),fun(minute),second);

}
