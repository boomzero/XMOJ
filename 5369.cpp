#include <bits/stdc++.h>

using namespace std;
int n, m;
struct node {
    node *prev = nullptr, *next = nullptr;
    int val = 0;
};

int main() {
    cin >> n >> m;
    node *head = new node, *tail = head;
    head->val = 1;
    for (int i = 2; i <= n; ++i) {
        node *p = new node;
        tail->next = p;
        p->val = i;
        p->prev = tail;
        tail = p;
    }
    tail->next = head;
    head->prev = tail;
    node *curr = head;
    while (true) {
        for (int i = 1; i < m; ++i) {
            curr = curr->next;
        }
        cout << curr->val << endl;
        node *del = curr;
        if (del->prev == del) {
            delete del;
            break;
        }
        del->prev->next = del->next;
        del->next->prev = del->prev;
        curr = del->next;
        delete del;
    }
    return 0;
}

