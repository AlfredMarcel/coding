/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-11 10:55:43
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count(int a,int b,int i,vector<int>& t){
    for(;i<t.size();i++){
        if(a==t[i])return b;
        if(b==t[i])return a;
    }
    return a;
}

int minSideJumps(vector<int>& obstacles) {
    int flog=2;
    int sum=0;
    for(int i=0;i<obstacles.size();i++){
        if(obstacles[i]==flog){
            if(obstacles[i-1]!=0){
                vector<int>tmp={1,2,3};
                for(int p:tmp){
                    if(p!=obstacles[i]&&p!=obstacles[i-1]){
                        flog=p;
                        break;
                    }
                }
                sum++;
            }else{
                int a,b;
                if(obstacles[i]==1){a=2;b=3;}
                if(obstacles[i]==2){a=1;b=3;}
                if(obstacles[i]==3){a=1;b=2;}
                flog=count(a,b,i,obstacles);
                sum++;
            }
        }
    }
    return sum;
}

vector<int>vec={0,0,2,0,0,0};

int main(void){
    cout<<minSideJumps(vec);
}
