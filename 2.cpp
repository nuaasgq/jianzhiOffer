//替换空格
//解题思路就是用另一个字符串来代替原字符串寻找空格位置，从而修改原字符串
class Solution {
public:
	void replaceSpace(char *str,int length) {
		char str1[length+1];
		for(int i=0;i<length+1;i++)
			str1[i]=str[i];
		int j=0;
		for(int i=0;i<length+1;i++)
		{
			if(str1[i]==' ')
			{
				str[j++]='%';
				str[j++]='2';
				str[j++]='0';
			}
			else
				str[j++]=str1[i];
		}

	}
};