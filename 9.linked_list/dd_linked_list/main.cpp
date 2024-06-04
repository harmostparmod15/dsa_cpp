#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *convertArr2DL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node *removeHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;

    delete tail;

    return head;
}

Node *removeAtK(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    int count = 0;

    // finding k element from llist
    while (temp)
    {
        count++;
        if (count == k)
            break;

        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == NULL && front == NULL)
        return NULL;

    else if (prev == NULL)
        return removeHead(head);
    else if (front == NULL)
        return removeTail(head);

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node *removeEl(Node *head, int val)
{
    Node *temp = head;
    int count = 0;
    // int k = 0;

    while (temp)
    {
        count++;

        if (temp->data == val)
            break;

        temp = temp->next;
    }
    return removeAtK(head, count);
}

void removeNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return;
}

Node *insertBeforeHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node *insertBeforeTail(Node *head, int val)
{
    if (head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prevTail = tail->back;
    Node *newNode = new Node(val, tail, prevTail);
    prevTail->next = newNode;
    tail->back = newNode;

    return head;
}

Node *insertBeforeK(Node *head, int k, int val)
{
    if (k == 1)
        return insertBeforeHead(head, val);
    Node *temp = head;
    int count = 0;

    while (temp)
    {
        count++;

        if (count == k)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertBeforeNode(Node *node, int val)
{
    Node *prev = node->back;
    Node *newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

Node *reverseDll(Node *head)
{
    // brute force T.C = o(2n) || S.C = o(n)
    // Node *temp = head;
    // stack<int> st;
    // storing elements in stack from ll
    // while (temp)
    // {
    //     st.push(temp->data);
    //     temp = temp->next;
    // }
    // temp = head;
    // storing back in ll from stack
    // while (temp)
    // {
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }
    // return head;

    // optimal T.C = o(n) || S.C = o(1)
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;

    Node *current = head;
    while (current != NULL)
    {

        prev = current->back;

        current->back = current->next;

        current->next = prev;

        current = current->back;
    }

    return prev->back;
}

int main()
{
    // creating and initializing array
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(8);

    //    getting the head of the doubly Linked list
    // Node *head = convertArr2DL(arr);
    // print(head);

    // -------------------------  DELETION -------------------------

    // ============================================================================
    // deletion of head in a doubly Linked list
    // Node *head = convertArr2DL(arr);
    // Node *newHead = removeHead(head);
    // print(newHead);

    // ============================================================================
    // deleteion of tail in a doubly linked list
    // Node *head = convertArr2DL(arr);
    // Node *newHead = removeTail(head);
    // print(newHead);

    // ============================================================================
    // remove elment at k position in the doubly linked list
    // Node *head = convertArr2DL(arr);
    // Node *newHead = removeAtK(head, 3);
    // print(newHead);

    // ============================================================================
    // remove elment with given value in the doubly linked list
    // Node *head = convertArr2DL(arr);
    // Node *newHead = removeEl(head);
    // print(newHead);

    // ============================================================================
    // remove given node from  the doubly linked list and node shouldnt be head
    // Node *head = convertArr2DL(arr);
    // removeNode(head->next);
    // print(head);

    // -------------------------  INSERTION -------------------------

    // ============================================================================
    // insert before head of doubly linked list
    // Node *head = convertArr2DL(arr);
    // Node *newHead = insertBeforeHead(head, 45);
    // print(newHead);

    // ============================================================================
    // insert before tail of doubly linked list
    // Node *head = convertArr2DL(arr);
    // Node *newHead = insertBeforeTail(head, 12);
    // print(newHead);

    // ============================================================================
    // insert before kth element of doubly linked list
    // Node *head = convertArr2DL(arr);
    // int k = 2;
    // int val = 14;
    // Node *newHead = insertBeforeK(head, k, val);
    // print(newHead);

    // ============================================================================
    // insert before given node   ( it shouldnt be head ) of doubly linked list
    // Node *head = convertArr2DL(arr);
    // insertBeforeNode(head->next, 14);
    // print(head);

    // ============================================================================
    // reverse a given doubly linked list
    // Node *head = convertArr2DL(arr);
    // Node *newHead = reverseDll(head);
    // print(newHead);

    return 0;
}