class BST {
private:
    TreeNode* root;

    // 内部递归函数：t 是父节点的 left 或 right 指针的“真身”
    void insert(int x, TreeNode* & t) {
        if (t == nullptr) {
            t = new TreeNode(x); // 找到了空位，直接在此处建房，自动连上父节点！
        } 
        else if (x < t->val) {
            insert(x, t->left);  // 比当前小，去左边找空位
        } 
        else if (x > t->val) {
            insert(x, t->right); // 比当前大，去右边找空位
        }
        // 如果相等，说明树里已经有了，什么都不做 (或者更新计数器)
    }
public:
    void insert(int x) { insert(x, root); }
};