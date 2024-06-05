#include <iostream>
#include <vector>
#include <map>
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

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
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

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

Node *findMiddleNode(Node *head)
{
    // brute T.C = o(n) + o(n/2) || S.C = o(1)
    // int count = 0;
    // Node *temp = head;
    // // find length of ll
    // while (temp != NULL)
    // {
    //     count++;
    //     temp = temp->next;
    // }
    // int midIndex = (count / 2) + 1;
    // temp = head;
    // // get node at mid index
    // while (temp != NULL)
    // {
    //     midIndex--;
    //     if (midIndex == 0)
    //         break;
    //     temp = temp->next;
    // }
    // return temp;

    // optimal T.C = o(n/2) || S.C = o(1)
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseLL(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool detectLoop(Node *head)
{
    // brute T.C = o(n) || S.C = o(n)
    // Node *temp = head;
    // map<Node *, int> mpp;
    // while (temp)
    // {
    //     if (mpp.find(temp) != mpp.end())
    //         return true;
    //     mpp[temp] = 1;
    // temp = temp->next;
    // }
    // return false;

    // optimal  T.C = o(n) || S.C = o(1)
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

Node *startOfLoop(Node *head)
{

    // brute T.C = o(n) || S.C = o(n)
    // Node *temp = head;
    // map<Node *, int> mpp;
    // while (temp)
    // {
    //     if (mpp.find(temp) != mpp.end())
    //         return temp;
    //     mpp[temp] = 1;
    //     temp = temp->next;
    // }
    // return NULL;

    // optimal  T.C = o(n) || S.C = o(1)
    // step - 1 >>> detecting a loop
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // step - 2 >>> finding the starting point
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int lengthOfLoop(Node *head)
{
    // brute T.C = o(n) || S.C = o(n)
    // Node *temp = head;
    // int timer = 1;
    // map<Node *, int> mpp;
    // while (temp)
    // {
    //     if (mpp.find(temp) != mpp.end())
    //     {
    //         int val = mpp[temp];
    //         return timer - val;
    //     }
    //     mpp[temp] = timer;
    //     timer++;
    //     temp = temp->next;
    // }
    // return 0;

    // optimal
    Node *fast = head;
    Node *slow = head;
    int count = 0;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
        {
            count = 1;
            fast = fast->next;
            while (slow != fast)
            {
                count++;
                fast = fast->next;
            }
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return count;
}

Node *oddAndEven(Node *head)

{
    if (head == NULL || head->next == NULL)
        return head;
    // brute T.C = o(2n) || S.C = o(n)
    // Node *temp = head;
    // vector<int> v;
    // // 1 :  odd num
    // while (temp->next->next != NULL)
    // {
    //     v.push_back(temp->data);
    //     temp = temp->next->next;
    // }
    // v.push_back(temp->data);
    // // 2 : even num
    // temp = head->next;
    // while (temp->next != NULL)
    // {
    //     v.push_back(temp->data);
    //     temp = temp->next->next;
    // }
    // v.push_back(temp->data);
    // // 3 : convert arr to ll
    // return convertArr2LL(v);

    // optimal T.C = o(n) || S.C = o(1)
    Node *odd = head;
    Node *even = head->next;
    Node *firstEvenNode = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = firstEvenNode;
    return head;
}

Node *removeNthNodeBack(Node *head, int n)
{
    // brute
    // Node *temp = head;
    // int count = 0;
    // // 1 : find length of ll
    // while (temp != NULL)
    // {
    //     count++;
    //     temp = temp->next;
    // }
    // // 2 : if n is length of ll
    // if (n == count)
    // {
    //     Node *newHead = head->next;
    //     free(head);
    //     return newHead;
    // }
    // // 3 : traverse till index node
    // int index = count - n;
    // temp = head;
    // while (temp != NULL)
    // {
    //     if (index == 0)
    //     {
    //         Node *deleteNode = temp->next;
    //         temp->next = temp->next->next;
    //         delete deleteNode;
    //         break;
    //     }
    //     index--;
    //     temp = temp->next;
    // }
    // return head;

    // optimal

    Node *fast = head;
    Node *slow = head;
    // 1 : move fast by 1 step for n times
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    // if n is length of LL then return head + 1 as new head
    if (fast == NULL)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    // 3 : move fast and slow by 1 step till fast reach at last element
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *delNode = slow->next;

    slow->next = slow->next->next;
    delete delNode;

    return head;
}

int main()

{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    // arr.push_back(6);
    // arr.push_back(13);
    // arr.push_back(65);

    // ================================================================
    // find the middle node  of linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = findMiddleNode(head);
    // cout << newHead->data;

    // ================================================================
    // reverse a singly linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = reverseLL(head);
    // print(newHead);

    // ================================================================
    // detect  a loop in  singly linked list
    // Node *head = convertArr2LL(arr);
    // bool ans = detectLoop(head);

    // ================================================================
    // find the starting of  a loop in  singly linked list
    // Node *head = convertArr2LL(arr);
    // Node *newHead = startOfLoop(head);

    // ================================================================
    // find the length of  a loop in  singly linked list
    // Node *head = convertArr2LL(arr);
    // int ans  = lengthOfLoop(head);

    // ================================================================
    // seggregate odd and even nodes in linked list
    // Node *head = convertArr2LL(arr);
    // Node *ans = oddAndEven(head);
    // print(ans);

    // ================================================================
    // remove nth node from the end of linked list
    // Node *head = convertArr2LL(arr);
    // int n = 2;
    // Node *ans = removeNthNodeBack(head, n);
    // print(ans);

    return 0;
}