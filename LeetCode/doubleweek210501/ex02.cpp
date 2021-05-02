/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-01 22:47:54
 */

#include <iostream>
#include <vector>
#include <string>
#include<set>
#include<unordered_map>

using namespace std;

class SeatManager {
    set<int>open_seats;
    unordered_map<int,int>tab;
public:
    SeatManager(int n) {
        for(int i=0;i<n;i++){
            open_seats.insert(i);
            tab[i]=0;
        }
    }
    
    int reserve() {
        int res=*(open_seats.begin())+1;
        tab[res-1]=1;
        open_seats.erase(res-1);
        return res;
    }
    
    void unreserve(int seatNumber) {
        if(tab[seatNumber-1]==0){
            tab[seatNumber-1]=1;
            open_seats.erase(seatNumber-1);
        }else{
            tab[seatNumber-1]=0;
            open_seats.insert(seatNumber-1);
        }
    }
};

int main(void){
    
}
