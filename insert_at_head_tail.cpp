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
int size(Node *head){
    Node* tmp = head;
    int cnt = 0;
    while(tmp!=NULL){
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
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
void insert_at_head_with_position(Node* &head,Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void insert_at_end(Node* &tail,int val){
    Node* newNode = new Node(val);
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
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
    cout<<endl;
    cout<<"Enter position: ";
    int p;cin>>p;
    if(p==0){
        insert_at_head_with_position(head,tail,7);
    }
    else if(p==size(head)){
        insert_at_end(tail,7);
    }
    else if(p<size(head)){
        insert_at_position(head,p-1,7);
    }
    else cout<<"Invalid"<<endl;
    print_normal(head);
    cout<<endl;
    print_reverse(tail);
    return 0;
}