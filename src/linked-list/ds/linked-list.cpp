#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node* next;
    node(){
        val = 0;
        next = nullptr;
    };
    node(int v){
        val = v;
        next = nullptr;
    };
};

class Solution{
    public:
        void insert(node* head, int val){
            while(head->next){
                head = head->next;
            }
            node* newNode = new node(val);
            head->next = newNode;
        }
        node* reverse(node* head){
            node *prev = nullptr, *rest;
            while(head){
                rest = head->next;
                head->next = prev;
                prev = head;
                head = rest;
            }
            head = prev;
            return head;
        }
        void show(node* head){
            while(head){
                cout<<head->val<<" ";
                head = head->next;
            }
            cout<<endl;
        }
};

int main(){
    Solution solve;
    node* head = new node();

    for(int i=0; i<5; i++){
        solve.insert(head, i);
    }
    solve.show(head);
    head = solve.reverse(head);
    solve.show(head);

    return 0;
}