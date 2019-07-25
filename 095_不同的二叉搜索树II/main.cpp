/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
从1到n枚举每一个值作为根节点，把每次生成的二叉树结构的根节点都保存下来

假设其中一次是以i为根节点，树的节点值为begin <= i <= end，其步骤如下：
1. 用{begin, i-1}递归生成左子树的所有结构，并将所有结构的根节点保存在lSubs
2. 用{i+1,end}递归生成右子树的所有结构，并将所有结构的根节点保存在rSubs
3. 在以i为根节点的前提下，遍历lSubs和rSubs的每一个节点，将i节点值生成的新节点作为他们的根节点；将该结构存入返回列表
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n <=0) 
            return vector<TreeNode*> {};
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int begin, int end){
        vector<TreeNode*> ret;
        if(begin > end){
            ret.push_back(nullptr); // 注意：必须加入空指针
            return ret;
        }
            
        for(int i = begin; i<=end; ++i){
            vector<TreeNode*> lSubs = generate(begin,i-1);  // {begin,i-1}所有结构的根节点列表
            vector<TreeNode*> rSubs = generate(i+1, end);   // {i+1, end}所有结构的根节点列表
            for(auto l: lSubs){
                for(auto r: rSubs){
                    TreeNode *root = new TreeNode(i);   // 注意：root节点在该处生成
                    root->left = l;
                    root->right = r;
                    ret.push_back(root);
                }
            }
        }
        
        return ret;
    }
};