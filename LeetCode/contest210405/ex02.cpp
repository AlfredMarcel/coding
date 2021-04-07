/*
 * @Description: lc 春季赛  AC
 * @Author: Marcel
 * @Date: 2021-04-05 15:32:35
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int orchestraLayout(int num, int xPos, int yPos) {
    int layer1=min(xPos,num-yPos-1);
    int layer2=min(num-xPos-1,yPos);
    int layer=min(layer1,layer2);
    long long nums=0;
    /*
    for(int i=0;i<layer;i++){
        nums+=(long long)4*(num-1-2*i);
        nums%=9;
    }*/
    nums=(long long)4*(num-layer)*layer%9;

    if(xPos==layer){
        nums+=yPos-layer;
        nums%=9;
    }else if(num-yPos-1==layer){
        nums+=num-2*layer;
        nums+=xPos-layer-1;
        nums%=9;
    }else if(num-xPos-1==layer){
        nums+=2*(num-2*layer)-2;
        nums+=num-yPos-layer-1;
        nums%=9;
    }else if(yPos==layer){
        nums+=3*(num-2*layer)-3;
        nums+=num-xPos-layer-1;
        nums%=9;
    }
    return nums+1;
}

int main(void){

    cout<<orchestraLayout(1e9,1e9-1,1e9-1);
    
    


}

