/*
 * @Description: 用另一个栈，记录主栈个时刻最小值的状态。
 * @Author: Marcel
 * @Date: 2021-04-08 15:23:40
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MinStack {

    vector<int>min_vec;
    vector<int>vec;

public:
    /** initialize your data structure here. */
    MinStack() {
        min_vec={};
        vec={};
    }
    
    void push(int val) {
        vec.push_back(val);
        if(min_vec.size()==0)min_vec.push_back(val);
        else min_vec.push_back((val<min_vec.back())?val:min_vec.back());
    }
    
    void pop() {
        vec.pop_back();
        min_vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return min_vec.back();
    }
};

int main(void){
    
}
