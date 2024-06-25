#include<iostream>
using namespace std:





    ListNode* reverseLinkedList(ListNode* head) {
 
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* front = temp->next;

            temp->next = prev;

            prev = temp;

            temp = front;
        }
        return prev;
    }


    ListNode* getKthNode(ListNode* temp, int k) {

        k -= 1;

        while (temp != NULL && k > 0) {

            k--;
            temp = temp->next;
        }
        return temp;
    }

    
    ListNode* kReverse(ListNode* head, int k) {
        
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {
            ListNode* kThNode = getKthNode(temp, k);
            if (kThNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }
            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseLinkedList(temp);

        
            if (temp == head) {
                head = kThNode;
            } else {
                prevLast->next = kThNode;
            }

            
            prevLast = temp;

            temp = nextNode;
        }

        
        return head;
    }


    ListNode* findNthNode(ListNode* temp, int k) {
            int count = 1;
            while (temp != NULL) {

                if(count == k) return temp;
                count++;
                temp = temp->next;
            }
            return temp;
        }








    ListNode* rotateKTime(ListNode* head,int k) {
        if (head == NULL || k == 0)
            return head;

        ListNode* temp = head;
        // find length of linked list
        int len = 1;
        while (temp->next != NULL) {
            len++;
            temp = temp->next;
        }
        if (k % len == 0)
            return head;

        k = k % len;

        temp->next = head;
        // find nth node i.e len - k node
       ListNode* newLastNode = findNthNode(head, len - k);
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }








ListNode* merge(ListNode* list1, ListNode* list2){
  
    ListNode* dummyNode = new Node(-1);
    ListNode* res = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    // Connect the remaining
    // elements if any
    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }

    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}








ListNode* flattenLinkedList(ListNode* head){
    // If head is null or there 
    // is no next node, return head
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Recursively flatten the
    // rest of the linked list
    ListNode* mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}



int main(){

//  1: 
        //reverse k pair of singly linked list
        // ListNode*head =  kReverse(head , k);
    
//  2:
        // rotate a linked list k times
        // ListNode*head = rotateKTime(head , 5)

//  3:
        // flattening of linked list
        // ListNode*head = flattenLinkedList(head);


};