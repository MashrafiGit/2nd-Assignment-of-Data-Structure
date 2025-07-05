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

void find_element_from_linked_list(Node *head, int x)
{
    Node *tmp = head;
    int idx = 0;

    while (tmp != NULL)
    {
        if (tmp->val == x)
        {
            cout << idx << endl;
            return;
        }
        tmp = tmp->next;
        idx++;
    }

    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
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
            }
            linked_list_insert_at_tail(head, tail, val);
        }

        long long int x;
        cin >> x;
        find_element_from_linked_list(head, x);
    }

    return 0;
}