#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ===== PASTE YOUR partition FUNCTION HERE =====
    ListNode* partition(ListNode* head, int x) {
 // ListNode*less=nullptr;
        ListNode*lhead=nullptr;
        ListNode*ltail=nullptr;
        // ListNode*great=nullptr;
        ListNode*ghead=nullptr;
        ListNode*gtail=nullptr;
        ListNode*i=head;
        while(i != nullptr){
            if(i->val < x) {
                 if(lhead == nullptr){
                     ListNode* less=new ListNode();
                      less->val=i->val;
                      less->next=NULL;
                      lhead=less;
                      ltail=less;
                      
                 }
                 else{
                    ListNode*less=new ListNode();
                    less->val=i->val;
                    less->next=NULL;
                    ltail->next=less;
                    ltail=less;
                 }
            }
            else {
                //   if(i->val >= x) {
                 if(ghead == nullptr){
                      ListNode* great=new ListNode();
                      great->val=i->val;
                      great->next=NULL;
                      ghead=great;
                      gtail=great;
                      
                 }
                 else{
                    ListNode* great=new ListNode();
                    great->val=i->val;
                    great->next=NULL;
                    gtail->next=great;
                    gtail=great;
                 }
            }
            // }
            i=i->next;
        }
        ltail->next=ghead;
        return ltail;
    }
    // ==============================================
};

// Build a linked list from a vector
ListNode* buildList(const vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : v) {
        ListNode* node = new ListNode(val);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

// Print the list. Stops after 50 nodes so a cycle can't hang the program.
void printList(ListNode* head) {
    if (!head) { cout << "(empty list / nullptr)\n"; return; }
    int count = 0;
    while (head && count < 50) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
        count++;
    }
    if (head) cout << " ... (more than 50 nodes: possible cycle!)";
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int x;
    cin >> x;

    ListNode* head = buildList(v);

    cout << "Before: ";
    printList(head);

    Solution sol;
    ListNode* result = sol.partition(head, x);

    cout << "After:  ";
    printList(result);
    return 0;
}