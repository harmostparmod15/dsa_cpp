#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfLL(Node *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

bool searchInLL(Node *head, int target)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == target)
            return true;
        temp = temp->next;
    }
    return false;
}

Node *removeHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *removeTail(Node *head)
{
    Node *temp = head;
    if (temp == NULL || temp->next == NULL)
        return NULL;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node *removeAtK(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removeEl(Node *head, int val)
{
    if (head == NULL)
        return NULL;

    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertHead(Node *head, int val)
{
    if (head == NULL)
        return NULL;
    Node *temp = new Node(val);
    temp->next = head;
    return temp;
}

Node *insertLast(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    Node *temp = head;
    while (temp)
    {
        if (temp->next == NULL)
        {
            Node *el = new Node(val);
            temp->next = el;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertAtK(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val);
        else
            return NULL;
    }
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k - 1)
        {
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{

    // creating and initializing array
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(8);

    // ============================================================================
    // getting the head of the Linked list
    // Node* head = convertArr2LL(arr);

    // ============================================================================
    // printing the whole Linked list
    // while(head){
    //     cout<<head->data<<" ";
    //     head = head->next;
    // }

    // ============================================================================
    // length of Linked list
    // Node* head2 = convertArr2LL(arr);
    // int len = lengthOfLL(head2);
    // cout<<"length of linked list is : "<<len;

    // ============================================================================
    // find a element in linked list
    // Node* head3 = convertArr2LL(arr);
    // int target = 12;
    // bool ans = searchInLL(head3 , target);
    // cout<<ans;

    // -------------------------  DELETION -------------------------

    // ============================================================================
    // deletion of head in a Linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = removeHead(head);
    // cout << newHead->data;

    // ============================================================================
    // deleteion of tail in a linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = removeTail(head);
    // printLL(newHead);

    // ============================================================================
    // remove elment at k position in the linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = removeAtK(head, 3);
    // printLL(newHead);

    // ============================================================================
    // remove elment with given value in the linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = removeEl(head, 8);
    // printLL(newHead);

    // -------------------------  INSERTION -------------------------

    // ============================================================================
    // insert at head of linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = insertHead(head, 45);
    // printLL(newHead);

    // ============================================================================
    // insert at head of linked list
    // // Node *head = convertArr2LL(arr);
    // Node *newHead = insertHead(head, 45);
    // // printLL(newHead)

    // ============================================================================
    // insert at last of linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = insertLast(head, 45);
    // printLL(newHead);

    // ============================================================================
    // insert at kth position  of linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = insertAtK(head, 45, 4);
    // printLL(newHead);

    return 0;
}