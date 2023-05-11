struct ListNode {//链表结构体
    int val;
    ListNode *next;//指向下一个节点的指针
    ListNode() : val(0), next(nullptr) {}//默认构造函数,空指针
    ListNode(int x) : val(x), next(nullptr) {}//构造函数
    ListNode(int x, ListNode *next) : val(x), next(next) {}//构造函数
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        else if (l2 == nullptr) {
            return l1;
        }
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
void test01() {
    ListNode* list1 = new ListNode(2, new ListNode(3, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(2, new ListNode(3)));
    Solution s;
    ListNode* ans = s.mergeTwoLists(list1, list2);
    while (ans != nullptr) {
        cout << ans->val << "  ";
        ans = ans->next;
    }
    cout << endl;
}//合并两个有序链表
int main(){
    test01();
    system("pause");
    return 0;
}