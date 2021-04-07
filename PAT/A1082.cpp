/*
 * @Description: PAT A1082  21/25 最后一个测试点没过
 * @Author: Marcel
 * @Date: 2021-04-01 13:50:20
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string>weight={"Qian","Bai","Shi"};
vector<string>num={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string input;
int length;

/*处理四位数字，转成中文读法字符串，尾部不带空格*/
/*第一个ling要留下，后面的ling要忽略   0080  ling ba Shi*/
string handle(string a){
    string t_res="";
    string tmp;
    int l=a.length();
    if(l==1){
        t_res+=num[a[0]-'0'];
    }
    if(l==2){
        tmp=num[a[0]-'0'];
        if(tmp!="ling"){
            t_res+=tmp+" Shi";
        }else{
            t_res+=tmp;
        }
        tmp=num[a[1]-'0'];
        if(tmp!="ling"){
            t_res+=" "+tmp;
        }
    }
    if(l==3){
        tmp=num[a[0]-'0'];
        if(tmp!="ling"){
            t_res+=tmp+" Bai";
        }else{
            t_res+=tmp;
        }
        tmp=num[a[1]-'0'];
        if(tmp!="ling"){
            t_res+=" "+tmp+" Shi";
        }
        tmp=num[a[2]-'0'];
        if(tmp!="ling"){
            t_res+=" "+tmp;
        }
    }
    if(l==4){
        tmp=num[a[0]-'0'];
        if(tmp!="ling"){
            t_res+=tmp+" Qian";
        }else{
            t_res+=tmp;
        }
        tmp=num[a[1]-'0'];
        if(tmp!="ling"){
            t_res+=" "+tmp+" Bai";
        }
        tmp=num[a[2]-'0'];
        if(tmp!="ling"){
            t_res+=" "+tmp+" Shi";
        }
        tmp=num[a[3]-'0'];
        if(tmp!="ling"){
            t_res+=" "+tmp;
        }
    }
    if(t_res=="")return "ling";
    else return t_res;
}

int main(void){
    string res="";
    ios::sync_with_stdio(false);
    cin>>input;
    if(input[0]=='-'){
        res+="Fu ";
        input=input.substr(1);
    }
    length=input.length();
    if(length<=4){
        res+=handle(input);
    }else if(length<=8){
        string temp=handle(input.substr(0,length-4));
        if(temp!="ling"){
            res+=temp+" Wan";
        }
        temp=handle(input.substr(length-4));
        if(temp!="ling"){
            res+=" "+temp;
        }
    }else{
        string temp=handle(input.substr(0,1));
        if(temp!="ling"){
            res+=temp+" Yi";
        }
        temp=handle(input.substr(1,4));
        if(temp!="ling"){
            res+=" "+temp+" Wan";
        }
        temp=handle(input.substr(5));
        if(temp!="ling"){
            res+=" "+temp;
        }
    }
    if(res==""){
        cout<<"ling";
    }else{
        cout<<res;
    }
    
}
