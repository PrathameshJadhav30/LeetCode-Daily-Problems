//Problem Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description
// Date: 01/11/2025
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mpp(nums.begin(), nums.end());

        // Remove nodes from the beginning if present in nums
        while (head && mpp.count(head->val))
            head = head->next;

        // Traverse the rest of the list
        ListNode* curr = head;
        while (curr && curr->next) {
            while (curr->next && mpp.count(curr->next->val)) {
                curr->next = curr->next->next;  // Skip the node
            }
            curr = curr->next;
        }
        return head;
    }
};

// Helper function to create linked list from vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> listVals = {1, 2, 3, 4, 5, 6, 7};
    vector<int> numsToRemove = {3, 5, 7};

    // Create linked list
    ListNode* head = createList(listVals);

    cout << "Original List: ";
    printList(head);

    // Call function
    Solution obj;
    ListNode* modified = obj.modifiedList(numsToRemove, head);

    cout << "Modified List: ";
    printList(modified);

    return 0;
}
