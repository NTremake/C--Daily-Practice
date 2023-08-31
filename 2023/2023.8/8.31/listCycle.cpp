#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode1 {
    int val;
    ListNode1 *next;
    ListNode1(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode1 *head) {
        unordered_set<ListNode1 *> seen;
        while(head != nullptr) {
            if(seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return 0;
    }
};
class Solution {
public:
    bool hasCycle(ListNode1* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode1 *slow = head;
        ListNode1 *fast = head->next;
        if(slow == fast) {
            return true;
        }
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// 检查链表有没有环