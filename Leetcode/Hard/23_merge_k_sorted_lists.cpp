/*******************************************************************
* https://leetcode.com/problems/merge-k-sorted-lists/
* Hard
* 
* Conception: 
*  1. 
*
* You are given an array of k linked-lists lists,
* each linked-list is sorted in ascending order.
*
* Merge all the linked-lists into one sorted linked-list and return it.
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.
*
*******************************************************************/
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
// Method 1
class Solution {
public:
    ListNode* mergeTwo(ListNode *fir, ListNode *sec){
        if(!fir && !sec)
        return NULL;
        
        if(fir && !sec)
        return fir;
        
        if(!fir && sec)
        return sec;
        
        ListNode *merged = new ListNode(0);
        ListNode *head = merged;
        
        while(fir && sec){
            if(fir->val<=sec->val){
                merged->next=fir;
                fir=fir->next;
            }else{
                merged->next=sec;
                sec=sec->next; 
            }
            
            merged=merged->next;
        }
        merged->next=fir?fir:sec;
        return head->next;
    }
    
    ListNode* merge(vector<ListNode*>& lists,int last){
        while(last!=0){
        int i = 0, j = last;
            while(i < j){
                lists[i] = mergeTwo(lists[i], lists[j]);
                ++i;
                --j;

                if(i>=j){
                    last = j;
                    break;
                }
            }
        }
        return lists[0];
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        return NULL;
        
        return merge(lists, lists.size()-1);
    }
};

// Method 2
class Solution {    
    struct NodeComp{
        bool operator()(const ListNode* a, const ListNode* b){ return a->val >= b->val; }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, std::vector<ListNode*>, NodeComp> pq; // minheap
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) pq.push(lists[i]);
        }        
        ListNode* ans = new ListNode(-1);// dummy
        ListNode* cur = ans;
        while(!pq.empty()){
            ListNode* top = pq.top();// grab the top
            pq.pop(); // pop it out
            ListNode* next = top->next; // grab the next
            top->next = nullptr; // ground the top            
            cur->next = top; // connect it to ans
            cur = cur->next; // update cursor
            if(next)  pq.push(next);
        }
        return ans->next;
    }
};