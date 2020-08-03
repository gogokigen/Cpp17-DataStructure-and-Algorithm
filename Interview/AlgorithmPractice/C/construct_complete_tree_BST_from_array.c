//https://www.geeksforgeeks.org/construct-complete-binary-tree-given-array/
#include <stdio.h>

struct Node { 
    int data; 
    struct Node* left, * right; 
}; 


struct Node* newNode(int data) { 

    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 

    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
}

  

struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n){ 

    // Base case
    if (i < n){ 

        struct Node* temp = newNode(arr[i]); 
        root = temp; 

        // insert left child 
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n); 

        // insert right child 
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n); 
    }
    return root; 
} 

struct Node* constructBST(int arr[], struct Node* root, int i, int n){ 

    // Base case
    if (i < n){
        struct Node* temp = newNode(arr[i]); 
        root = temp; 

        // insert left child 
        if(arr[i] <= root->data){
            root->left = constructBST(arr, root->left, i+1, n); 
        }else if (arr[i] > root->data){
        // insert right child 
            root->right = constructBST(arr, root->right, i+1, n); 
        }
    }
    return root; 
}

void inOrder(struct Node* root) { 

    if (root != NULL) { 
        inOrder(root->left); 
        printf("%d ", root->data);
        inOrder(root->right); 
    } 
} 

int main(){

    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    struct Node* root = insertLevelOrder(arr, root, 0, n); 
    inOrder(root); // 6 4 6 2 5 1 6 3 6 

    printf("\n");

    struct Node* root2 = constructBST(arr, root2, 0, n); 
    inOrder(root2); // 6 6 6 6 5 4 3 2 1 

    return 0;
}