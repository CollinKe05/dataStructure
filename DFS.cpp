struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归查找：代码极其简洁，本质是让操作系统帮你维护调用栈
TreeNode* DFS_Find(TreeNode* root, int target) {
    if (root == nullptr) return nullptr;         // 撞南墙了，没找到
    if (root->val == target) return root;        // 找到了
    
    // 先去左边深挖
    TreeNode* leftResult = DFS_Find(root->left, target);
    if (leftResult != nullptr) return leftResult;
    
    // 左边没找到，再去右边深挖
    return DFS_Find(root->right, target);
}