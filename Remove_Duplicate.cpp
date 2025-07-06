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

void linked_list_print(Node *head)
{
    if (head == NULL)
    {
        cout << endl;
        return;
    }

    Node *tmp = head;
    cout << tmp->val;
    tmp = tmp->next;
    while (tmp != NULL)
    {
        cout << " " << tmp->val;
        tmp = tmp->next;
    }
    cout << endl;
}

void linked_list_insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
        return;
    }
    newNode->next = head;
    head = newNode;
}

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

void linked_list_duplicate_remove(Node *head)
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        Node *tmp = i;
        while (tmp->next != NULL)
        {
            if (tmp->next->val == i->val)
            {
                // cout << "ok" << endl;
                Node *deleteNode = tmp->next;
                tmp->next = deleteNode->next;
                delete deleteNode;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        linked_list_insert_at_tail(head, tail, val);
    }

    linked_list_duplicate_remove(head);
    linked_list_print(head);

    return 0;
}