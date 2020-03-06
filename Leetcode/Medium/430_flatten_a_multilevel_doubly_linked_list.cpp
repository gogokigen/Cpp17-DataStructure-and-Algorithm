/*******************************************************************
* https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
* Medium
* 
* Conception: use stacke and doule linkedlist
*
* Given a doubly linked list which in addition to the next and previous pointers,
* it could have a child pointer, which may or may not point to a separate doubly linked list.
* These child lists may have one or more children of their own, and so on,
* to produce a multilevel data structure, as shown in the example below.
*
* Flatten the list so that all the nodes appear in a single-level,
* doubly linked list. You are given the head of the first level of the list.
*
* Example:
*
*
* Key:
*  1. doule linkedlist!
*
*******************************************************************/
#include <iostream>
#include <bits/stdc++.h>  //stack
using namespace std;


class Node {
public:
    Node(){};

    int val;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;
};

class Solution {
public:
    Solution(){};
    
    // Solution 1: but heap_error
    stack <Node> pendingNode;
    void listChain(Node* result_head, Node* head){
        result_head = head;
        
        if(head->next == NULL && head->child == NULL){
            if(this->pendingNode.size()!= 0 ){
                //result_head->next = NULL;
                //return;
            //} else {
                Node* sub_head = &this->pendingNode.top();
                this->pendingNode.pop();
                result_head->next = sub_head;
                listChain(result_head->next, sub_head->next);
            }
        } else if(head->next != NULL && head->child != NULL){
            Node *sub_head = head->next;
            pendingNode.push(*sub_head);
            result_head->next = head->child;
            listChain(result_head->next, head->child);
        } else if(head->next != NULL){
            result_head->next = head->next;
            listChain(result_head->next, head->next);
        }
    }

    Node* flatten_heap_error(Node* head) {
        Node* listNode;
        if (head != NULL){
            listNode = head;
            listChain(listNode, head);
        }

        return listNode;
    }
    
    // Solution 2:
    Node* flatten(Node* head) {
        stack <Node*> tmpNode;
        Node* tmp = head;

        while(tmp){
            if(tmp->child != NULL){
                if(tmp->next != NULL){
                    tmpNode.push(tmp->next);
                }
                tmp->next = tmp->child;
                tmp->child->prev = tmp;
                tmp->child = NULL;
                tmp = tmp->next;
            } else {
                if(tmp->next == NULL){
                    if(tmpNode.size()!= 0 ){
                        tmp->next = tmpNode.top();
                        tmp->next->prev = tmp;
                        tmp = tmp->next;
                        tmpNode.pop();
                    } else {
                        break;
                    }
                }else{
                    tmp = tmp->next;
                }
            }
        }
        return head;
    }
};

int main()
{
    //Test Cases
    Node node[12];
    node[0].val = 1;
    node[0].next = &node[1];

    node[1].val = 2;
    node[1].prev = &node[0];
    node[1].next = &node[2];

    node[2].val = 3;
    node[2].prev = &node[1];
    node[2].next = &node[3];
    node[2].child = &node[6];
    
    node[3].val = 4;
    node[3].prev = &node[2];
    node[3].next = &node[4];

    node[4].val = 5;
    node[4].prev = &node[3];
    node[4].next = &node[5];

    node[5].val = 6;
    node[5].prev = &node[4];

    node[6].val = 7;
    node[6].next = &node[7];

    node[7].val = 8;
    node[7].prev = &node[6];
    node[7].next = &node[8];
    node[7].child = &node[10];

    node[8].val = 9;
    node[8].prev = &node[7];
    node[8].next = &node[9];

    node[9].val = 10;
    node[9].prev = &node[8];
    
    node[10].val = 11;
    node[10].next = &node[11];

    node[11].val = 12;
    node[11].prev = &node[10];


    Solution* sol = new Solution;
    Node* result_head;
    result_head = sol->flatten(&node[0]);
    Node* tmp = result_head;
    
    for(int i = 0; i < 12; i++){
        cout << "result_head: " <<tmp->val<< endl;
        tmp = tmp->next;
    }

    return 0;
}