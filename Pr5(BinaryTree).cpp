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

/*
• Preorder Traversal (Root → Left → Right)
• Inorder Traversal (Left → Root → Right)
• Postorder Traversal (Left → Right → Root)
• Algorithm for creating a new node
Step 1: Create a structure for a tree node containing family member name and pointers to left and right
Children.
Step 2: Create nodes dynamically for each family member.
Step 3: Connect nodes to form a family tree.
Preorder Traversal Algorithm
1. Visit the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.
Inorder Traversal Algorithm
1. Traverse the left subtree.
2. Visit the root node.
3. Traverse the right subtree.
Postorder Traversal Algorithm
1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the root node.
*/