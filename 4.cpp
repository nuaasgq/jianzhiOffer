/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //题目描述
/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}
和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
解题思路：先根据前序遍历确定中序遍历的根节点，再根据中序遍历根节点左侧的节点位于左子树，
右侧的节点位于右子树的特点，不断的递归重建二叉树。
*/
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int len=vin.size();
		if(!len)
			return NULL;
		TreeNode *head=new TreeNode(pre[0]);
		int temp=0;//用来标识根节点在中序遍历中的位置
		for(int i=0;i<len;i++)
		{
			if(pre[0]==vin[i])
			{
				temp=i;
				break;
			}
		}
		vector<int> preleft,preright,vinleft,vinright;
		for(int i=0;i<temp;i++)//中序遍历根节点左侧的节点位于左子树，右侧的节点位于右子树。
		{
			vinleft.push_back(vin[i]);
			preleft.push_back(pre[i+1]);//pre[0]是根节点
		}
		for(int i=temp+1;i<len;i++)
		{
			vinright.push_back(vin[i]);
			preright.push_back(pre[i]);
		}
		head->left=reConstructBinaryTree(preleft,vinleft);
		head->right=reConstructBinaryTree(preright,vinright);
		return head;

    }
};

//另附完整测试代码
#include <iostream>
#include<vector>
using namespace std;



  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int len=vin.size();
		if(!len)
			return NULL;
		TreeNode *head=new TreeNode(pre[0]);
		int temp=0;//用来标识根节点在中序遍历中的位置
		for(int i=0;i<len;i++)
		{
			if(pre[0]==vin[i])
			{
				temp=i;
				break;
			}
		}
		vector<int> preleft,preright,vinleft,vinright;
		for(int i=0;i<temp;i++)//中序遍历根节点左侧的节点位于左子树，右侧的节点位于右子树。
		{
			vinleft.push_back(vin[i]);
			preleft.push_back(pre[i+1]);//pre[0]是根节点
		}
		for(int i=temp+1;i<len;i++)
		{
			vinright.push_back(vin[i]);
			preright.push_back(pre[i]);
		}
		head->left=reConstructBinaryTree(preleft,vinleft);
		head->right=reConstructBinaryTree(preright,vinright);
		return head;
    }
	
	int PreTraverse(TreeNode* head)//前序遍历
	{
		if(head==NULL)
			return 0;
		cout<<head->val;
		PreTraverse(head->left);
		PreTraverse(head->right);
		return 0;
	}

	int VinTraverse(TreeNode* head)//中序遍历
	{
		if(head==NULL)
			return 0;
		VinTraverse(head->left);
		cout<<head->val;
		VinTraverse(head->right);
		return 0;
	}

	int PostTraverse(TreeNode* head)//后序遍历
	{
		if(head==NULL)
			return 0;
		PostTraverse(head->left);
		PostTraverse(head->right);
		cout<<head->val;
		return 0;
	}

	int main ( )
	{
		int a[]={1,2,4,7,3,5,6,8};
		int b[]={4,7,2,1,5,3,8,6};
		vector<int> pre(a,a+8);
		vector<int> vin(b,b+8);
		TreeNode* head=reConstructBinaryTree(pre,vin);
		PreTraverse(head);
		cout<<endl;
		VinTraverse(head);
		cout<<endl;
		PostTraverse(head);
		system("pause");
		return 0;
	}
