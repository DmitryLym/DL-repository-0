#define ret 0

//функция печати адрес брата
tree * findBrother(tree *root, int key)
{
    //tree node = NULL;

    if (root == NULL || (root->left == NULL && root->right == NULL) )
        return ret;

    if ( key == root->key)
    {
         if (root->parent == NULL)
         {
           return ret;
         }

        root = root->parent;
        if (key < root->key)
        {
            root = root->right;
            if (root==NULL)
            {
                return ret;
            }
            else return (root);
        }
        if (key > root->key)
        {
            root = root->left;
            if (root==NULL)
            {
                return ret;
            }
            else return (root);
        }
    }


    if( key < root->key)
        findBrother( root->left,key);
    else
        findBrother( root->right,key);

    //return 0;
}
