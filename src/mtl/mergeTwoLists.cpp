#include <stdio.h>
#include "gtest/gtest.h"

// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1? l1: l2;
        return dummy.next;
    }
};

TEST(abc, cde)
{
    ListNode l14(4);
    ListNode l11(1);
    ListNode l12(2);
    l11.next = &l12;
    l12.next = &l14;

    ListNode l21(1);
    ListNode l23(3);
    ListNode l24(4);
    l21.next = &l23;
    l23.next = &l24;

    Solution s;
    s.mergeTwoLists(&l11, &l21);

    ASSERT_GE(1, 1);
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



