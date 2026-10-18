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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* start = new ListNode();   // 第一个节点
        ListNode* p = start;
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while (p1 && p2) {
            if (p1->val > p2->val) {
                p->val = p2->val;
                p2 = p2->next;
            } else {
                p->val = p1->val;
                p1 = p1->next;
            }
            // 只有还有数据要写，才新建下一个节点
            if (p1 && p2) {
                p->next = new ListNode();
                p = p->next;
            }
        }

        // 把剩下的接上
        while (p1) {
            p->next = new ListNode(p1->val);
            p = p->next;
            p1 = p1->next;
        }
        while (p2) {
            p->next = new ListNode(p2->val);
            p = p->next;
            p2 = p2->next;
        }

        return start;
    }
};