#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode *slow = head, *fast = head->next;
        while (fast != head && fast->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast == head)
            return slow->next;
        else
            return slow;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head;
    ListNode* middle = solution.findMiddle(head);
    cout << "Middle element: " << middle->val << endl;

    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
