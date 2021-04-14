/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-14 12:33:42
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node{
    char val;
    //mark=1表示存在该char的结尾词，mark=0说明这是前缀
    int mark;
    vector<Node*>next;

    Node(char v,vector<Node*>tmp,int m){
        val=v;
        next=tmp;
        mark=m;
    }
    Node(){

    }
};

class Trie {

    Node root;
    Node* current;

public:
    /** Initialize your data structure here. */
    Trie() {
        root=Node('0',vector<Node*>(26,nullptr),0);
        current=&root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        current=&root;
        for(char s:word){
            if(current->next[s-'a']==nullptr){
                Node* tmp=new Node(s,vector<Node*>(26,nullptr),0);
                current->next[s-'a']=tmp;
            }
            current=current->next[s-'a'];
        }
        //表示单词结尾
        current->mark=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        current=&root;
        bool res=true;
        for(char s:word){
            if(current->next[s-'a']==nullptr){
                res=false;
                break;
            }
            current=current->next[s-'a'];
        }
        //search 需要判断单词结尾
        if(current->mark==0)res=false;
        return res;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        current=&root;
        bool res=true;
        for(char s:prefix){
            if(current->next[s-'a']==nullptr){
                res=false;
                break;
            }
            current=current->next[s-'a'];
        }
        return res;
    }
};

int main(void){
    Trie trie =Trie();
    trie.insert("apple");
    trie.search("apple");   // 返回 True
    trie.search("app");     // 返回 False
    trie.startsWith("app"); // 返回 True
    trie.insert("app");
    trie.search("app");     // 返回 True

}

