#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *toFind = NULL, *dup = NULL;

        while (curr != NULL && curr->next != NULL){
            toFind = curr;
     
            while (toFind->next != NULL){
                if (curr->val == toFind->next->val){
    
                    dup = toFind->next;
                    toFind->next = toFind->next->next;
                    dup = NULL;
                }else {
                    toFind = toFind->next;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

int main(){
    
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = NULL;
    
    Solution* sol = new Solution();
    
    ListNode* result = sol->deleteDuplicates(head);
    
    
    while(result){
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}
