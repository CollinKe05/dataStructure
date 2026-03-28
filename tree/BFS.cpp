#include <queue>

// 层次遍历 / 广度查找
TreeNode* BFS_Find(TreeNode* root, int target) {
    if (root == nullptr) return nullptr;
    
    std::queue<TreeNode*> q;
    q.push(root); // 根节点入队
    
    while (!q.empty()) {
        TreeNode* curr = q.front(); 
        q.pop(); // 队头出队
        
        if (curr->val == target) return curr;
        
        // 左右孩子依次排到队伍最后面
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
    return nullptr; // 找遍了全树都没找到
}