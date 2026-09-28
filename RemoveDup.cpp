#include <iostream>
#include <vector>
#include <string>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr != nullptr){
            if(curr->val != curr->next->val){
                 prev = curr;
                 curr= prev->next;
            }
            else curr = curr->next;
        }
        return dummy->next;
    }
};

// Build a linked list from a vector
ListNode* buildList(const vector<int>& v) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int x : v) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

// Convert a linked list back to a vector
vector<int> toVector(ListNode* head) {
    vector<int> v;
    while (head != nullptr) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
}

string show(const vector<int>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); i++) {
        s += to_string(v[i]);
        if (i + 1 < v.size()) s += ",";
    }
    return s + "]";
}

int main() {
    struct Test {
        vector<int> input;
        vector<int> expected;
    };

    vector<Test> tests = {
        {{1, 2, 2, 2, 3}, {1, 3}},      // long run in the middle
        {{1, 1, 2, 3},    {2, 3}},      // head deleted (dummy node case)
        {{1, 2, 2},       {1}},         // run at the tail
        {{1, 1, 1},       {}},          // everything deleted
        {{},              {}},          // empty list
        {{5},             {5}},         // single node
        {{1, 2, 3},       {1, 2, 3}},   // no duplicates
        {{1, 1, 2, 2, 3, 3}, {}},       // all values duplicated
        {{1, 2, 3, 3, 4, 4, 5}, {1, 2, 5}} // the LeetCode example
    };

    Solution sol;
    int passed = 0;

    for (size_t i = 0; i < tests.size(); i++) {
        ListNode* head = buildList(tests[i].input);
        ListNode* result = sol.deleteDuplicates(head);
        vector<int> got = toVector(result);

        bool ok = (got == tests[i].expected);
        if (ok) passed++;

        cout << "Test " << i + 1 << ": " << (ok ? "PASS" : "FAIL") << "\n"
             << "  input    : " << show(tests[i].input) << "\n"
             << "  expected : " << show(tests[i].expected) << "\n"
             << "  got      : " << show(got) << "\n\n";
    }

    cout << passed << " / " << tests.size() << " tests passed\n";
    return 0;
}