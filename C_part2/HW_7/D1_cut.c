//функция печати дерева сверху левый бок
void printUpLeft(tree* root)
{
    if(root == NULL)
    return;
    if(root->left)
        printUpLeft(root->left);
    printf("%d ",root->key);

}

//функция печати дерева сверху правый бок
void printUpRight(tree* root)
{
    if(root == NULL)
    return;
    printf("%d ",root->key);
    if(root->right)
    {
        printUpRight(root->right);

    }


}

//функция печати дерева сверху
void btUpView(tree* root)
{
    if(root == NULL)
    return;
   printUpLeft(root->left);
   printf("%d ",root->key);
   printUpRight(root->right);


}
