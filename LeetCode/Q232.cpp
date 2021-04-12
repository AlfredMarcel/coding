/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-12 12:32:39
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

class MyQueue {

    stack<int>in;
    stack<int>out;

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out.empty())load();
        int tmp=out.top();
        out.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if(out.empty())load();
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty()&&out.empty();
    }

private:
    void load(){
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }

};

int main(void){
    
}
