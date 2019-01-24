class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() -1;
        int ret = 0;

        while(l < r){
            ret = max(min(height[l], height[r]) *(r-l), ret);
            if(height[l] < height[r]){ // 移动较小的值，才可能获得更大面积
                l ++; 
            } else{
                r --;
            }
        }
        return ret;
    }
};