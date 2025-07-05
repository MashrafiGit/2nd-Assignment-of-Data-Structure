#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long int val;
    Node *next;

    Node(long long int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void linked_list_insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

long long int minimum_value_in_linked_list(Node *head)
{
    long long int min = INT_MAX;
    for (Node *i = head; i != NULL; i = i->next)
    {
        if (min > i->val)
            min = i->val;
    }
    return min;
}

long long int maximum_value_in_linked_list(Node *head)
{
    long long int max = INT_MIN;
    for (Node *i = head; i != NULL; i = i->next)
    {
        if (max < i->val)
            max = i->val;
    }
    return max;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    long long int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
            ;
        }
        linked_list_insert_at_tail(head, tail, val);
    }

    long long int min = minimum_value_in_linked_list(head);
    long long int max = maximum_value_in_linked_list(head);

    int diff = max - min;

    cout << diff << endl;

    return 0;
}