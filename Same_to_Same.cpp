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

void linked_list_print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

void check_if_both_linked_list_are_same(Node *head1, Node *tail1, Node *head2, Node *tail2)
{
    if (tail1->val != tail2->val)
    {
        cout << "NO" << endl;
    }
    else
    {

        for (Node *i = head1, *j = head2; i != NULL; i = i->next, j = j->next)
        {
            // cout << i->val << " " << j->val << endl;
            if (i->val != j->val)
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    long long int val1;
    while (true)
    {
        cin >> val1;
        if (val1 == -1)
        {
            break;
        }
        linked_list_insert_at_tail(head1, tail1, val1);
    }

    Node *head2 = NULL;
    Node *tail2 = NULL;

    long long int val2;
    while (true)
    {
        cin >> val2;
        if (val2 == -1)
        {
            break;
        }
        linked_list_insert_at_tail(head2, tail2, val2);
    }

    check_if_both_linked_list_are_same(head1, tail1, head2, tail2);

    return 0;
}