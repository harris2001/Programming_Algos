#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

int main(){
    
    struct Node* head = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    
    head -> data = 0;
    head -> next = first;
    
    first -> data = 1;
    first -> next = second;
    
    second -> data = 2;
    second -> next = NULL;
    
    struct Node* point;
    
    point = head;
    
    while(point!=NULL){
        printf("%d ",point->data);
        point = point -> next;
    }
    
    return 0;
}
