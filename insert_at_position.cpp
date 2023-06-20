#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insert_at_tail(Node* &head,Node* &tail,int v){
    Node* newNode = new Node(v);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}

void print_normal(Node* &head){
    Node* tmp = head;
    while(tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
}
void print_reverse(Node* &tail){
    Node* tmp = tail;
    while(tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->prev;
    }
}
void insert_at_position(Node* head,int p,int v){
    Node* newNode = new Node(v);
    Node* tmp = head;
    while(p--){
        tmp=tmp->next;
    }
    newNode->next=tmp->next;
    tmp->next=newNode;
    newNode->next->prev=newNode;
    newNode->prev=tmp;

}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    while(true){
        int x;cin>>x;
        if(x==-1) break;
        insert_at_tail(head,tail,x);
    }
    print_normal(head);
    cout<<endl;
    print_reverse(tail);
    cout<<endl<<"In which position do you want to insert?: ";
    int p;cin>>p;
    cout<<endl<<"What is the value?: ";
    int v;cin>>v;
    insert_at_position(head,p-1,v);
    print_normal(head);
    cout<<endl;
    print_reverse(tail);
    return 0;
}