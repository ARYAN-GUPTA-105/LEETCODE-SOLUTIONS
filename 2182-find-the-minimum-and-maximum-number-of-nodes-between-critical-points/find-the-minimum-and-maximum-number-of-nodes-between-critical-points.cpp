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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr)
            return {-1, -1};
        vector<int> dist;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1;
        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                dist.push_back(pos);
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }
        if (dist.size() < 2)
            return {-1, -1};
        int mn = INT_MAX;
        for (int i = 1; i < dist.size(); i++) {
            mn = min(mn, dist[i] - dist[i - 1]);
        }
        int mx = dist.back() - dist.front();
        return {mn, mx};
    }
};