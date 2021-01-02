#include<bits/stdc++.h>

using namespace std;

struct Node{
    bool endpoint;
    Node *nodes[26];
    Node(){
        endpoint = false;
        for(int i=0; i<26; i++) nodes[i] = nullptr;
    }
}*root;

void insert(string word){
    Node* curr = root;
    for(int i=0; i<word.size(); i++){
        int id = word[i] - 'a';
        if(curr -> nodes[id] == nullptr){
            curr -> nodes[id] = new Node();
        }
    }
    curr->endpoint = true;
}

bool search(string word){
    Node* curr = root;
    for(int i=0; i<word.size(); i++){
        int id = word[i] - 'a';
        if(curr->nodes[id] == nullptr) return false;
    }
    return curr->endpoint;
}

int main(){
    root = new Node();
    insert("ritoo");
    insert("sumu");
    insert("rabiul");
    insert("badhon");

    if(search("sumu")) cout<<"OK"<<endl;
    return 0;
}