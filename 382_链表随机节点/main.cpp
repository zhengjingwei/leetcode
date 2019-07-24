/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL)); // srand( (time(NULL) )中time(NULL)函数是得到一个从1900年1月1日到现在的时间秒数，这样每一次运行程序的时间的不同就可以保证得到不同的随机数了。
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i = 2;
        int ret = head->val;
        ListNode* p = head->next;
        while(p){
            if (rand() % i == 0)
                ret = p->val;
            i++;
            p = p->next;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */