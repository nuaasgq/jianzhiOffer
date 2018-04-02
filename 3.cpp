//从尾到头打印链表 
//思路就是遍历链表，利用insert函数的特性不断的在vector变量头部插入新元素 一定要牢记vector的常用操作
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> val;
		vector<int> val1;
            while(head!=NULL)
		    {
			    val.insert(val.begin(),head->val);
			    head=head->next;
		    }
		
		return val;
    }
};