/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-04 17:29:02
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

int count(ListNode * head){
    int res=0;
    while(head!=nullptr){
        res++;
        head=head.next;
    }
    return res;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len_a;
    int len_b;
    len_a=count(headA);
    len_b=count(headB);

    while(len_a!=0&&len_b!=0){
        if(headA==headB)return headA;
        lf(len_a>len_b){
            headA=headA.next;
            len_a--;
        }else if(len_a<len_b){
            headB=headB.next;
            len_b--;
        }else{
            headA=headA.next;
            len_a--;
            headB=headB.next;
            len_b--;
        }
    }
    return nullptr;       
}

int main(void){
    
}
