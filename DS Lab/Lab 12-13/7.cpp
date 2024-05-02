#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* mid(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = head;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    }
    return slow;
}


TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    ListNode* midNode = mid(head);
    TreeNode* root = new TreeNode(midNode->val);

    if (head == midNode) {
        return root;
    }

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midNode->next);
    return root;
}

void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}

int main() {
    ListNode* head = new ListNode(8);
    head->next = new ListNode(10);
    head->next->next = new ListNode(12);
    head->next->next->next = new ListNode(15);
    head->next->next->next->next = new ListNode(18);
    head->next->next->next->next->next = new ListNode(20);
    head->next->next->next->next->next->next = new ListNode(25);

    TreeNode* root = sortedListToBST(head);

    printTree(root);
    return 0;
}