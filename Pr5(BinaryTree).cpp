#include <iostream>
using namespace std;

struct Node
{
    string name;
    Node *left, *right;

    Node(string n)
    {
        name = n;
        left = right = NULL;
    }
};

void showTree(Node *root, int space = 0)
{
    if (root == NULL)
        return;

    space += 5;

    showTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << root->name << endl;

    showTree(root->left, space);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->name << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->name << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->name << " ";
}

int main()
{
    Node *root = new Node("Grandfather");

    root->left = new Node("Father");
    root->right = new Node("Uncle");

    root->left->left = new Node("Me");
    root->left->right = new Node("Sister");

    root->right->left = new Node("Cousin1");
    root->right->right = new Node("Cousin2");

    cout << "Family Tree:\n";
    showTree(root);

    cout << "\n\nPreorder Traversal:\n";
    preorder(root);

    cout << "\n\nInorder Traversal:\n";
    inorder(root);

    cout << "\n\nPostorder Traversal:\n";
    postorder(root);

    return 0;
}