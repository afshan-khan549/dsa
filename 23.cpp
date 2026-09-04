/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include <vector>
#include <queue>

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};