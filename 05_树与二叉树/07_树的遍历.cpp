// 树的先根遍历
void PreOrder(TreeNode *R)
{
    if (R != NULL)
    {
        visit(R); // 访问根结点
        while (R还有下一个子树)
            PreOrder(T);
    }
}

// 树的后根遍历
void PostOrder(TreeNode *R)
{
    if (R != NULL)
    {
        while (R还有下一个子树)
            PostOrder(T);
        visit(R); // 访问根结点
    }
}


