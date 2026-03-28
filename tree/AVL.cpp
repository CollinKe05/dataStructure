// Weiss 风格的单旋转（指针的移花接木）
// k2 是失衡的那个老根节点
void rotateWithLeftChild(TreeNode* & k2) {
    TreeNode* k1 = k2->left;     // 锁定老根的左孩子 k1
    
    k2->left = k1->right;        // ① k1 的右孩子过继给老根 k2 当左孩子
    k1->right = k2;              // ② 老根 k2 降级，变成 k1 的右孩子
    
    // ③ 高度更新 (略去具体的高度的加减代码)
    // k2->height = max(height(k2->left), height(k2->right)) + 1;
    // k1->height = max(height(k1->left), k2->height) + 1;
    
    k2 = k1;                     // ④ 权力交接：由于传的是引用，这句话直接让整棵树的新根变成了 k1
}