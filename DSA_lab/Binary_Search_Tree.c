#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *NODE;

NODE insert(NODE node, int value)
{
    NODE tmp;
    tmp = (NODE)malloc(sizeof(struct Node));
    tmp->key = value;
    tmp->left = tmp->right = NULL;
    if (node == NULL)
    {
        return tmp;
    }
    if (value < node->key)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->key)
    {
        node->right = insert(node->right, value);
    }
    return node;
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->key);
        inorder(root->right);
    }
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->key);
    }
}

NODE getSuccessor(NODE curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

NODE delete(NODE root, int x)
{
    if (root == NULL)
        return root;
    if (root->key > x)
        root->left = delete(root->left, x);
    else if (root->key < x)
        root->right = delete(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            NODE temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            NODE temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            NODE succ = getSuccessor(root);
            root->key = succ->key;
            root->right = delete(root->right, succ->key);
        }
    }
    return root;
}

int main()
{
    NODE root_node = NULL;
    int n, p, data, key;
    for (;;)
    {
        printf("\n1.insert\t2.delete\t3.postorder\t4.inorder\t5.preorder\t6.exit\n");
        printf("\nread choice\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter no of elements to be inserted\n");
            scanf("%d", &p);
            for (int i = 0; i < p; i++)
            {
                printf("enter element to be added\n");
                scanf("%d", &data);
                root_node = insert(root_node, data);
            }
            break;
        case 2:
            printf("\n enter the node to be deleted\n");
            scanf("%d", &key);
            root_node = delete(root_node, key);
            break;
        case 3:
            postorder(root_node);
            break;
        case 4:
            inorder(root_node);
            break;
        case 5:
            preorder(root_node);
            break;
        default:
            exit(0);
            break;
        }
    }
}
