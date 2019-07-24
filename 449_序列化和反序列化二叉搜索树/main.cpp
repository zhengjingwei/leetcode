/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ret = to_string(root->val);
        ret.push_back(',');
        ret += serialize(root->left);
        ret += serialize(root->right);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nums;
        
        // 切割数据
        while(!data.empty()){
            int pos = data.find(',');
            int val = stoi(data.substr(0,pos));
            nums.push_back(val);
            data = data.substr(pos+1);
        }
        
        return buildTree(nums,0, nums.size() -1);
    }
    
    // 从先序遍历序列重建二叉搜索树
    TreeNode* buildTree(vector<int> &nums, int begin, int end) {
        if(begin > end || begin < 0 || end >= nums.size())
            return nullptr;
        TreeNode *root = new TreeNode(nums[begin]);
        int lh = begin + 1;
        while(lh <= end && nums[lh] < root->val)
            lh ++;  // 第一个大于root值的坐标
        root->left = buildTree(nums, begin + 1, lh-1);  // 递归构建左子树
        root->right = buildTree(nums, lh, end);         // 递归构建右子树
        return root;
    }    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));