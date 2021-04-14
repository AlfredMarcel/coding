/*
 * @Description: 层序遍历，每一层都是回文串的方法
 * @Author: Marcel
 * @Date: 2021-04-14 16:36:39
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

bool judge(deque<TreeNode*>que){
    bool res=true;
    while(que.size()>1){
        if(que.front()==nullptr||que.back()==nullptr){
            if(!(que.front()==nullptr&&que.back()==nullptr)){
                res=false;
                break;    
            }
        }else{
            if(que.front()->val!=que.back()->val){
                res=false;
                break;
        }
        }
        
        que.pop_back();
        que.pop_front();
    }
    return res;
}

bool levelorder(TreeNode* root){
    deque<TreeNode*>que1;
    deque<TreeNode*>que2;
    bool flag=true;
    que1.push_back(root);
    while(!(que1.empty()&&que2.empty())){
        while(!que1.empty()){
            TreeNode* tmp=que1.front();
            que1.pop_front();
            if(tmp!=nullptr){
                que2.push_back(tmp->left);
                que2.push_back(tmp->right);
            }
        }
        if(!judge(que2)){
            flag=false;
            break;
        }
        swap(que1,que2);        
    }
    
    return flag;
}


bool isSymmetric(TreeNode* root) {
    return levelorder(root);
}

int main(void){
    TreeNode* b=new TreeNode(3);
    TreeNode* c=new TreeNode(4);
    TreeNode* bb=new TreeNode(3);
    TreeNode* cc=new TreeNode(4);
    TreeNode* a=new TreeNode(2,b,c);
    TreeNode* aa=new TreeNode(2,cc,bb);
    TreeNode* root=new TreeNode(1,a,aa);
    cout<<isSymmetric(root);
    

}
