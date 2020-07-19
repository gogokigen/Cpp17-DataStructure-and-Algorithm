#include <stdio.h>
struct Node{
    struct Node* next;
    int val;
};

void dequeue(struct Node** ref){
    struct Node* target;
    struct Node* prev;
    if(*ref != NULL){
        target = *ref;
        while(target->next != NULL){
            prev = target;
            target = target->next;
        }
        prev->next = NULL;
        free(target);
    }
}

void enqueue(struct Node** ref, int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = data;
    new_node->next = (*ref);
    *ref = new_node;
}

void traverse(struct Node** ref){
    while((*ref)->next != NULL){
        printf("%d\n", (*ref)->val);
        (*ref) = (*ref)->next;
    }
}

int main(){
    
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = 0;
    root->next = NULL;

    enqueue(&root, 0);
    enqueue(&root, 1);
    enqueue(&root, 2);
    enqueue(&root, 3);
    dequeue(&root);
    traverse(&root);

    return 0;
}