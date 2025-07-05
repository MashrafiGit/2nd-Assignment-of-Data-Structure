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

void linked_list_delete_any_pos(Node *&head, Node *&tail, int idx)
{
    if (head == NULL)
        return;

    if (idx == 0)
    {
        Node *deleteNode = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        delete deleteNode;
        return;
    }

    Node *tmp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        if (tmp->next == NULL)
            return;
        tmp = tmp->next;
    }

    if (tmp->next == NULL)
        return;

    Node *deleteNode = tmp->next;

    if (deleteNode == tail)
    {
        tail = tmp;
    }

    tmp->next = deleteNode->next;
    delete deleteNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;

    while (q--)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
        {
            linked_list_insert_at_head(head, tail, v);
            linked_list_print(head);
        }
        else if (x == 1)
        {
            linked_list_insert_at_tail(head, tail, v);
            linked_list_print(head);
        }
        else if (x == 2)
        {
            linked_list_delete_any_pos(head, tail, v);
            linked_list_print(head);
        }
    }

    return 0;
}