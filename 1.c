/*给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);//表示结果链表的头节点的前一个节点(哨兵节点)
        ListNode *a1 = l1;
        ListNode *a2 = l2;
        ListNode *_res = res;
        int carray = 0;//表示进位
        while(a1!=NULL||a2!=NULL)
        {
            int x = (a1==NULL)?0:a1->val;
            int y = (a2==NULL)?0:a2->val;
            int sum = x+y+carray;
            carray = sum/10;
            _res->next = new ListNode(sum%10);
            _res=_res->next;
            if(a1!=NULL) a1=a1->next;
            if(a2!=NULL) a2=a2->next;
        }
        if(carray>0)
            _res->next = new ListNode(carray);
        return res->next;
    }
};