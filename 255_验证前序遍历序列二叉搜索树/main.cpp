
// 递归方法：超时
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) return true;
        return check(preorder,0, preorder.size()-1);
    }
    
    bool check(vector<int>& preorder, int begin, int end){
        if(begin == end)
            return true;
        
        int less = begin;   // 比begin小的元素坐标
        int more = end+1;   // 第一次比begin大的元素坐标
        while(less+1 <= end && preorder[less+1] < preorder[begin])
            ++ less;
        while(more-1 >= begin+1  && preorder[more-1] > preorder[begin])
            -- more;
        
        // 如果不满足
        if(less != more-1)
            return false;
        
        // 全部比首元素小/大
        if(less == begin || more == end+1)
            return check(preorder, begin+1, end);
        
        return check(preorder, begin + 1, less) && check(preorder, more, end);
    }
};

// 栈
// 把每次的元素尝试放进一个栈中，如果比当前栈顶的要大，则说明至少要占用当前右结点（相当于在栈中顶替掉）
// 同时记录当前扫过的最大值作为下界。
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (!preorder.size()) return true;
        stack<int> st;
        st.push(preorder[0]);
        int lst = INT_MIN;
        for (int i=1;i<preorder.size();i++)
        {
            if (preorder[i] < lst) return false;
            while(!st.empty() && preorder[i] > st.top()) 
            {
                lst = max(lst, st.top());
                st.pop();
            }
            st.push(preorder[i]);
        }
        return true;
    }
};