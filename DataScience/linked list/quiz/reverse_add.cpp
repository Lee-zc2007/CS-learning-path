#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

ListNode* createNode(int val) {
    ListNode* node = new ListNode(val);
    return node;
}

void appendNode(ListNode*& head, ListNode*& tail, int val) {
    ListNode* newNode = createNode(val);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

ListNode* addReversedLists(ListNode* l1, ListNode* l2) {
    ListNode* resultHead = nullptr;
    ListNode* resultTail = nullptr;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int digit = sum % 10;
        
        appendNode(resultHead, resultTail, digit);
        
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    
    return resultHead;
}

ListNode* buildLinkedList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        appendNode(head, tail, val);
    }
    
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    
    ListNode* l1 = buildLinkedList(m);
    ListNode* l2 = buildLinkedList(n);
    
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    ListNode* result = addReversedLists(l1, l2);
    
    result = reverseList(result);
    
    printLinkedList(result);
    
    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(result);
    
    return 0;
}