#include <iostream>
#include <vector>
#include <stack>
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
        cout << temp->data << "   ";
        temp = temp->next;
    }
    cout << endl;
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

Node *removeMiddle(Node *head)
{
    // optimal T.C = o(n/2)|| S.C = o(1)
    Node *slow = head;
    Node *fast = head;
    Node *beforeSlow = slow;
    if (head == NULL || head->next == NULL)
        return NULL;
    while (fast != NULL && fast->next != NULL)
    {
        beforeSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    beforeSlow->next = beforeSlow->next->next;
    delete slow;
    return head;
}

Node *findMiddleVersion2(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge2List(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if (list1)
        temp->next = list1;
    else
        temp->next = list2;
    return dummyNode->next;
}

Node *sortLL(Node *head)
{
    // brute  T.C = ( o(n) + o(logn) + o(n) )  S.C = o(n)
    // 1 : take out from ll and put in vector and sort vector
    // vector<int> v;
    // Node *temp = head;
    // while (temp != NULL)
    // {
    //     v.push_back(temp->data);
    //     temp = temp->next;
    // }
    // sort(v.begin(), v.end());
    // // 2 : put back in ll
    // temp = head;
    // int i = 0;
    // while (temp != NULL)
    // {
    //     temp->data = v[i];
    //     i++;
    //     temp = temp->next;
    // }
    // return head;

    // optimal
    if (head == NULL || head->next == NULL)
        return head;

    Node *middle = findMiddleVersion2(head);
    Node *leftHead = head;
    Node *rightHead = middle->next;
    middle->next = NULL;

    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);

    return merge2List(leftHead, rightHead);
}

Node *sortZeroOneTwo(Node *head)
{
    // brute T.C = o(2n) || S.C = o(1)
    // Node *temp = head;
    // int cnt0 = 0;
    // int cnt1 = 0;
    // int cnt2 = 0;
    // while (temp != NULL)
    // {
    //     if (temp->data == 0)
    //         cnt0++;
    //     else if (temp->data == 1)
    //         cnt1++;
    //     else
    //         cnt2++;
    //     temp = temp->next;
    // }
    // temp = head;
    // while (temp != NULL)
    // {
    //     if (cnt0 > 0)
    //     {
    //         temp->data = 0;
    //         cnt0--;
    //     }
    //     else if (cnt1 > 0)
    //     {
    //         temp->data = 1;
    //         cnt1--;
    //     }
    //     else
    //     {
    //         temp->data = 2;
    //         cnt2--;
    //     }
    //     temp = temp->next;
    // }
    // return head;

    // optimal T.C =o(n) || S.C = o(1)
    if (head == NULL || head->next == NULL)
        return head;
    // 1 : create 3 dummy LL and pointers to traverse in list
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;

    // 2 : inserting in the 3 created LL the values with pointers
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    // 3 : connecting the 3 pointers with one another
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    Node *newHead = zeroHead->next;
    // 4 : free up space
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

bool isPalindrome(Node *head)
{
    // brute T.C = o(2n) || S.C = o(n)
    // stack<Node *> st;
    // Node *temp = head;
    // // 1 : insert nodes in stack
    // while (temp)
    // {
    //     st.push(temp);
    //     temp = temp->next;
    // }
    // // 2 : compare top of stack node and current node of LL
    // temp = head;
    // bool flag = false;
    // while (temp != NULL)
    // {
    //     if (st.top()->data == temp->data)
    //     {
    //         flag = true;
    //         st.pop();
    //         temp = temp->next;
    //     }
    //     else
    //     {
    //         flag = false;
    //         break;
    //     }
    // }
    // return flag;

    // optimal T.C = o(2n) || S.C = o(1)
    Node *slow = head;
    Node *fast = head;
    // 1: find the middle node
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 2 :  reverse the LL after middle node
    Node *newHead = reverseLL(slow->next);

    // 3 : start comparing from start of LL and after middle of LL
    Node *first = head;
    Node *second = newHead;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            head = reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    head = reverseLL(newHead);
    return true;
}

Node *collison(Node *head1, Node *head2, int diff)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    // 1 : apply greater list pointer ( i.e temp2 ) to diff steps forward
    while (diff)
    {
        diff--;
        temp2 = temp2->next;
    }
    // 2 : now compare both LL for equality ,loop will break when both are equal either on a node or on null  ,  return any one of them
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

Node *intersectingPoint(Node *head1, Node *head2)
{
    // brute T.C = o( {n * map ki T.C [logn or 1] } + {n2 * map ki T.C [logn or 1] } ) ||  S.C = o(n1) if u r hashing 1st LL
    // map<Node *, int> mpp;
    // Node *temp = head1;
    // // 1: hashing the nodes from 1st LL
    // while (temp)
    // {
    //     mpp[temp] = 1;
    //     temp = temp->next;
    // }
    // // 2: checking the nodes from 2nd LL if they exist in our hashmap
    // temp = head2;
    // while (temp)
    // {
    //     if (mpp.find(temp) != mpp.end())
    //     {
    //         return temp;
    //     }
    //     temp = temp->next;
    // }
    // return NULL;

    // optimal

    // 1 : find length of 1st LL
    Node *temp = head1;
    int count1 = 0;
    while (temp)
    {
        count1++;
        temp = temp->next;
    }

    // 2 : find length of 2nd LL
    temp = head2;
    int count2 = 0;
    while (temp)
    {
        count2++;
        temp = temp->next;
    }
    // 3 : call the function with passing smaller list as first arguments which will do remaining steps
    int diff = abs(count1 - count2);
    if (count1 < count2)
    {
        return collison(head1, head2, count2 - count1);
    }
    else
    {
        return collison(head2, head1, count1 - count2);
    }
}

Node *addOne(Node *head)
{
    head = reverseLL(head);
    Node *temp = head;
    int carry = 1;

    while (temp != NULL)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    if (carry == 1)
    {
        Node *newNode = new Node(1);
        head = reverseLL(head);
        newNode->next = head;
        return newNode;
    }
    head = reverseLL(head);
    return head;
}

Node *addTwo(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    int carry = 0;
    // int sum = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
            sum = sum + temp1->data;
        if (temp2)
            sum = sum + temp2->data;

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }

    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

int main()

{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(1);
    // arr.push_back(14);
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(1);
    // arr.push_back(0);
    vector<int> brr;
    brr.push_back(1);
    brr.push_back(2);
    brr.push_back(0);
    // arr.push_back(0);

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

    // ================================================================
    // remove the middle node of a singly linked list
    // Node *head = convertArr2LL(arr);
    // Node *ans = removeMiddle(head);
    // print(ans);

    // ================================================================
    // check  singly linked list is palindrome or not
    // Node *head = convertArr2LL(arr);
    // bool ans = isPalindrome(head);
    // ans == true ? cout << "yes : " : cout << "no : ";

    // ================================================================
    // sort a singly linked list
    // Node *head = convertArr2LL(arr);
    // Node *ans = sortLL(head);
    // print(ans);

    // ================================================================
    // sort ll with 0s 1s 2s   singly linked list
    // Node *head = convertArr2LL(arr);
    // Node *ans = sortZeroOneTwo(head);
    // print(ans);

    // ================================================================
    // find the intersecting point of a  Y linked list
    // Node *head = convertArr2LL(arr);
    // Node *ans = intersectingPoint(head);
    // print(ans);

    // ================================================================
    // add 1 to a number represented by given linked list
    // Node *head = convertArr2LL(arr);
    // Node *ans = addOne(head);
    // print(ans);

    // ================================================================
    // add 2  numbers in   given linked list
    // Node *head = convertArr2LL(arr);
    // Node *head2 = convertArr2LL(brr);
    // Node *ans = addTwo(head, head2);
    // print(ans);

    return 0;
}