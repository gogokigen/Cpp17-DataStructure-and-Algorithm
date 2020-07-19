//https://www.prodevelopertutorial.com/remove-nth-node-from-end-of-list/

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
/*
struct Node * delete_node_from_end(struct Node *head, int num){

    struct Node *slow_pointer = head, *fast_pointer = head;

    for (int i = 0; i < num + 1; i++)
        fast_pointer = fast_pointer->next;

    while (fast_pointer->next) {
        fast_pointer = fast_pointer->next;
        slow_pointer = slow_pointer->next;
    }


    struct Node *node_to_be_deleted = slow_pointer->next;

    slow_pointer->next = slow_pointer->next->next;
    
    free(node_to_be_deleted);

    return head;
}
*/

void delete_nth_node_from_end(struct Node **ref, int nth){

    struct Node *slow_pointer = (*ref), *fast_pointer = (*ref);

    for (int i = 0; i < nth + 1; i++)
        fast_pointer = fast_pointer->next;

    while (fast_pointer->next) {
        fast_pointer = fast_pointer->next;
        slow_pointer = slow_pointer->next;
    }


    struct Node *node_to_be_deleted = slow_pointer->next;

    slow_pointer->next = slow_pointer->next->next;
    
    free(node_to_be_deleted);
}

int main(){
    
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = -1;
    root->next = NULL;

    enqueue(&root, 0);
    enqueue(&root, 1);
    enqueue(&root, 2);
    enqueue(&root, 3);
    //dequeue(&root);
    enqueue(&root, 4);
    enqueue(&root, 5);
    enqueue(&root, 6);
    //root = delete_node_from_end(root, 3);
    delete_nth_node_from_end(&root,3);
    traverse(&root); //0 1 3 4 5 6

    return 0;
}
