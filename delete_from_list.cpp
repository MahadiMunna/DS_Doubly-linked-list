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
void delete_tail(Node* &head,Node* &tail){
    Node* tmp = tail;
    tail=tail->prev;
    delete tmp;
    if(tail==NULL){
        head==NULL;
    }
    tail->next=NULL;
}
void delete_node(Node* &head,Node* &tail,int p){
    Node* tmp=head;
    if(p==0){
        head=tmp->next;
        delete tmp;
        if(head==NULL){
            tail=NULL;
            return;
        }
        head->prev=NULL;
        return;
    }
    else if(p==size(head)-1){
        delete_tail(head,tail);
        return;
    }
    else if(p<size(head)-1){
        for(int i=1;i<=p;i++){
        tmp=tmp->next;
    }
    tmp->next->prev=tmp->prev;
    tmp->prev->next=tmp->next;
    delete tmp;
    }
    else{
        cout<<"Invalid"<<endl; 
    }
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
    int p;cin>>p;
    delete_node(head,tail,p);
    cout<<endl;
    print_normal(head);
    cout<<endl;
    print_reverse(tail);
    return 0;
}