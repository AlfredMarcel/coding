/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-05 17:17:49
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeElements(ListNode* head, int val) {
    ListNode* node=new ListNode(-1,head);
    ListNode * cur=node;
    while(cur->next!=nullptr){
        if(cur->next->val==val){
            cur->next=cur->next->next;
        }else cur=cur->next;
    }
    return node->next;
}

int main(void){
    
    
}
