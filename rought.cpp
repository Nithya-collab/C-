#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     int count=0;
        for(ListNode*i=head;i!=NULL;i=i->next){
            count++;
        }
        ListNode*curr=head;
        if(abs(count-n) == 0) return NULL;
        else if(abs(count-n) == 1 && n==0) return head;
        n=abs(count-n);
        while(n>=2){
              curr = curr->next;
              n--;
        }
        if(n==0) {
            head = head->next; 
            return head;
        }
        curr->next = curr->next->next;
        return head;  
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) std::cout << " -> ";
        current = current->next;
    }
    std::cout << " -> nullptr" << std::endl;
}

// Helper function to free the allocated memory
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 1. Create a sample list data: [1, 2, 3, 4, 5]
    std::vector<int> values = {1, 2};
    int n = 2; // Node to remove from the end (e.g., 4)

    // 2. Build the linked list
    ListNode* head = createLinkedList(values);

    std::cout << "Original List: ";
    printList(head);

    // 3. Instantiate the solution and call the function
    Solution solution;
    ListNode* modifiedHead = solution.removeNthFromEnd(head, n);

    std::cout << "Modified List: ";
    printList(modifiedHead);

    // 4. Clean up allocated memory
    freeList(modifiedHead);

    return 0;
}
