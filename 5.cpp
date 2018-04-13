 //题目描述
/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
//解题思路：用stack1来储存入队元素。弹出时，如果stack2队列为空，先将stack1中的元素压入stack2，再将stack2的顶部元素弹出，做到先入先出。
  class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
		int a;
		if(stack2.empty())
		{
			while(!stack1.empty())
			{
				a=stack1.top();
				stack2.push(a);
				stack1.pop();
			}
		}
		a=stack2.top();
		stack2.pop();
		return a;
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};