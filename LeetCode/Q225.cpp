/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-13 10:55:19
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

class MyStack {
    /*输出队列*/
    queue<int>q1;
    /*输入队列*/
    queue<int>q2;

public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t=q1.front();
        q1.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

int main(void){
    
}
