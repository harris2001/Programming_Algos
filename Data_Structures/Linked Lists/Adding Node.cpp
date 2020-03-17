#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* Add_New_Node(int data){
    struct Node* temp = NULL;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
}

int main(){
    
    /*struct Node* head = NULL;
    struct Node* n1 = NULL;
    struct Node* n2 = NULL;
    struct Node* n3 = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    
    head -> data = 1;
    n1 -> data = 1;
    n2 -> data = 1;
    n3 -> data = 1;
    
    head -> next = n1;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = NULL;
    */
    int N;
    
    scanf("%d",&N);
    int dd;
    struct Node* tmp = NULL;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    
    for(int i=0; i<N; i++){
        scanf("%d",&dd);
        tmp = Add_New_Node(i);
        printf("%d",tmp->data);
    }
    
    
    return 0;
}
