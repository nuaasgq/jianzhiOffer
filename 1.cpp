//二维数组中的查找

//第一种方法思路很简单，就是先与每一行最大的比较，如果比这一行最大的还要大，
//目标位置就在更下面的行，否则目标位置就在这一行
/* class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int ilength=array.size();
        for(int i=0;i<ilength;i++)
        {
            if (array[i].empty())continue;
            int llength=array[i].size();
            if(target>array[i][llength-1])
                continue;
            else{
                for(int j=0;j<llength;j++)
                {
                    if(target==array[i][j])
                        return true;
                }
            }
        }
        return false;
    }
}; */

//第二种方法思路是选取左下角的那个点作为初始点，如果比它大就在右侧，比它小就在上侧
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int i=array.size()-1;
		int jlength=array[0].size()-1;
		int j=0;
        while(i>=0 && j<=jlength)
        {
            if (target==array[i][j])
				return true;
			else if(target>array[i][jlength])
				break;
			else if(target<array[i][j])
				i--;
			else 
				j++;	
    
        }
        return false;
    }
};