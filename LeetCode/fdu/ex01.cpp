/*
 * @Description: ex01
 * @Author: Marcel
 * @Date: 2021-07-06 10:12:02
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

/*麻烦在处理输入上*/
/*我们使用int数组来模拟输入，定义-0x3f3f3f3f为空指针值*/

#define N_INT -0x3f3f3f3f

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*建立二叉搜索树*/    
TreeNode* construct(vector<int>& vec){
    if(vec.empty())return nullptr;
    else{
        TreeNode* root= new TreeNode(vec.front());
        
        queue<TreeNode*>que;
        que.push(root);

        int cnt=0;
        for(int i=1;i<vec.size();i++){
            if(vec[i]!=N_INT){
                TreeNode* tmp=new TreeNode(vec[i]);
                //插到左子树
                if(cnt==0){
                    que.front()->left=tmp;
                    cnt++;
                }
                //插到右子树，并出队
                else if(cnt==1){
                    que.front()->right=tmp;
                    cnt=0;
                    que.pop();
                }
                //新节点入队
                que.push(tmp);
            }else{
                //如果是null，新结点，不进队
                if(cnt==0)cnt++;
                else if(cnt==1){
                    cnt=0;
                    que.pop();
                }
            } 
        }
        return root;
    }
}

/*k可能超过树中结点数量*/
void dfs(TreeNode* p,int &k){
    if(p==nullptr)return;
    dfs(p->left,k);
    if(--k==0)cout<<p->val;
    dfs(p->right,k);
    
}

int main(void){
    
    vector<int>vec={8,5,9,3,6,N_INT,N_INT,1};

    TreeNode* pp=construct(vec);    

    int k;
    cin>>k;

    if(k<=0)cout<<"k out of range!";
    dfs(pp,k);
    if(k>0)cout<<"k out of range!";
    
}
