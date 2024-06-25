#include<iostream>
using namespace std;


Node*head delelteNode(Node*head , int val){
    Node*temp = head;
    while(temp != NULL){
if(temp->next == data){
    // if temp is at ehad
    if(temp == head) head = head->next;
    // create next and previous node  to temp node
    Node* nextNode = temp ->next;
    Node* prevNode = temp->prev;
    // condition check and changing links of node
    if (nextNode) nextNode->prev = prevNode;
    if(prevNode) prevNode->next = nextNode;

    // free up memeory
    free(temp);
    temp = temp->next;
}else{
    // temp val is not equal to key ,, then simply go to next node
    temp = temp->next;
}
    }


}




Node* findTailNode(Node*head){
    Node* tail = head;
    while(tail->next != NULL ) tail = tail->next;
    return tail;
}


vector<int> findPairSumNode(Node*head , int targetSum){
    Node*left = head;
    Node*right = findTailNode(head);
    vector<int>v;
     // two pointer approach bcoz dll is sorted
    while(left->data < right ->data){

        // if left + right == target store in vector ,, and change the pointers
        if(left->data + right->data == targetSum){
            v.push_back(left->data);
            v.push_back(right->data);
            left = left->next;
            right = right->prev;
        }

        // sum is less so move the left pointer
        else if (left->data + right->data < targetSum) left = left->next;
        else right = right->prev;
    }
    return v;
}



Node* removeDuplicates(Node*head){
    Node*temp = head;
    while(temp != NULL && temp->next !=NULL){
        Node*nextNode = temp->next;
        // if nodes are same move the next node to unsimilar node
        while(nextNode != NULL && nextNode ->data == temp->data) nextNode = nextNode->next;
        // now change links of nodes , bcoz both nodes are different
        temp->next = nextNode;
        if (nextNode) nextNode->prev = temp;

// here temp next is pointing to nextnode so we can do temp = nextnode or temp = temp->next .
        temp = temp->next;
    }
    return head;
}




int main(){

//   1:
    // delete a node with given value in dll
    // deleteNode(head , 5);

//  2:
    // find pairs with given sum of a sorted doubly linked list
    // vector<int>ans = findPairSumNode(head , 12);

// `3:
    // remove duplicates from the sorted doubly linked list

}