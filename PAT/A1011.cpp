#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

double temp1,temp2,temp3;

int main(){
    string res;
    double res2=1;

    for(int i=0;i<3;i++){
        cin>>temp1>>temp2>>temp3;
        double choose=max(max(temp1,temp2),temp3);
        if(choose==temp1){
            res+="W ";
        }else if(choose==temp2){
            res+="T ";
        }else{
            res+="L ";
        }
        res2*=choose;
    }
    cout<<res<<setprecision(4)<<(res2*0.65-1)*2;
}