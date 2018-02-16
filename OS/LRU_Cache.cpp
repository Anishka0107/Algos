#include <bits/stdc++.h>
#define MAX_SIZE 7
#define MAX_PAGE 11
using namespace std;

class Node {
    public:
        int info;
        Node* next;
        Node* prev;

        Node(int info) {
            this->info = info;
            next = prev = NULL;
        }
};

class Queue {
    public:
        Node* start;
        Node* end;

        Queue() {
            start = end = NULL;
        }

        void push(int ele) {
            Node* n = new Node (ele);
            if (start == NULL) {
                start = end = n;
                return;
            }
            end->next = n;
            n->prev = end;
            end = n;
        }

        int pop() {
            // no need for conditions like start=NULL or start=end; they never occur
            int temp = start->info;
            start = start->next;
            delete start->prev;
            start->prev = NULL;
            return temp;
        }

        void print_queue() {
            Node* curr = start;
            while (curr) {
                cout << curr->info + 1 << " ";
                curr = curr->next;
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    Node* hm[MAX_PAGE] = {NULL};
    int curr_size = 0;
    while (true) {
        int page;
        cin >> page;
        page--;
        if (hm[page] == NULL) {
            if (curr_size >= MAX_SIZE) {
                int popped = q.pop();
                hm[popped] = NULL;
            } else {
                curr_size++;
            }
            q.push(page);
            hm[page] = q.end;
        } else {
            Node* old_pos = hm[page];
            q.push(page);
            hm[page] = q.end;
            if (old_pos->prev) {
                old_pos->prev->next = old_pos->next;
            } else {    // old_pos is starting position
                q.start = old_pos->next;  // this is never NULL
            }
            old_pos->next->prev = old_pos->prev;   // old_pos->next is bound to exist!
            delete old_pos;
        }
        q.print_queue();
    }
    return 0;
}
