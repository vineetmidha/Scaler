/*
Scaler Weekly Contest-2 Feb-2021
================================

Q-1: Partition List

Given a linked list A and a value B, partition it such that all nodes less than B come before nodes greater than or equal to B.
You should preserve the original relative order of the nodes in each of the two partitions. 

Constraints:
1 <= |A| <= 10^6
1 <= A[i], B <= 10^9

Output:
Return a pointer to the head of the modified linked list.

Input-1: 
A = [1,4,3,2,5,2]
B = 3

Output-1: [1,2,2,4,3,5]

Input-2:
A = [1,2,3,1,3]
B = 2

Output-2: [1,1,2,3,3]

Corner Cases:

Case-1:

A = [1,2,3,4,5]
B = 1

Output: [1,2,3,4,5]

Case-2:

A = [1,2,3,4,5]
B = 10

Output: [1,2,3,4,5]

*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode * insertNode(ListNode* head, ListNode* tail, int value) {
    ListNode * temp = new ListNode(value);

    if (head==NULL){
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    
    return head;
}

ListNode* Solution::partition(ListNode* head, int b) {
    if (head == NULL) return head;
    
    if (head->next == NULL) return head;
    
    ListNode * current = head;

    // head1 contains nodes < b
    
    ListNode * head1 = NULL;
    ListNode * tail1 = NULL;
    
    // head2 contains nodes with values >= b

    ListNode * head2 = NULL;
    ListNode * tail2 = NULL;

    while (current != NULL){
        ListNode * temp = new ListNode(current->val);
        
        if (current->val < b){
            //head1 = insertNode(head1, tail1, current->val);
            
            if (head1==NULL){
                head1 = tail1 = temp;
            } else {
                tail1->next = temp;
                tail1 = temp;
            }
            
        } else {
            // head2 = insertNode(head2, tail2, current->val);
            
            if (head2==NULL){
                head2 = tail2 = temp;
            } else {
                tail2->next = temp;
                tail2 = temp;
            }
        }
        current = current->next;
    }
    
    if (head1 == NULL){
        return head2;
    } else {
        tail1->next = head2;
        return head1;
    }
}
