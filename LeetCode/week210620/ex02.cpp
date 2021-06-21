/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-20 10:34:18
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int handle(string tmp){
    return stoi(tmp.substr(0,2))*60+stoi(tmp.substr(3));
}

int numberOfRounds(string startTime, string finishTime) {
    int start=handle(startTime);
    int end=handle(finishTime);
    if(end<start)end+=24*60;
    int ba1=start/15;
    int yu1=start%15;
    int ba2=end/15;
    int yu2=end%15;
    int sum=ba2-ba1;
    if(yu1!=0)sum--;
    return sum;
}

int main(void){
    
}
