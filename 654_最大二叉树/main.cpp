// 递归
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return helper(nums,0,nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums, int begin, int end){
        if(begin > end)
            return nullptr;
        int maxNum = INT_MIN;
        int index = begin;
        
        // 找最大值
        for(int i = begin; i<= end; ++i){
            if(maxNum < nums[i]){
                maxNum = nums[i];
                index = i;
            }
        }
        
        TreeNode* root = new TreeNode(maxNum);
        root->left = helper(nums,begin,index-1);    // 递归构建左子树
        root->right = helper(nums,index+1,end);     // 递归构建右子树
        return root;
    }
};