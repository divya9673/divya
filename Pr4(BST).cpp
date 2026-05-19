# include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
};
Node* createnode(int value){
    Node* newNode= new Node();
    newNode->val=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Node* insertnode(Node* root, int value){
    if(root==NULL){
        return createnode(value);
    }
    if(root->val > value){
        root->left=insertnode(root->left,value);
    }else{
        root->right=insertnode(root->right,value);
    }
    return root;
}
Node* findmin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int value){
    if(root==NULL){
        return NULL;
    }
    if(root->val < value){
        root->right=deleteNode(root->right,value);
    }else if(root->val > value){
        root->left=deleteNode(root->left,value);
    }else{
        if(root->left ==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if (root->left==NULL)
        {
            Node*temp=root->right;
            delete root;
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }else{
            Node* temp=findmin(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
        
    }
    return root;
}
Node* search(Node* root, int value){
    while(root!=NULL && root->val!=value){
        if(root->val > value){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    return root;
}
int countnode(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1 + countnode(root->left) + countnode(root->right);
}

int main(){
    Node* root=NULL;
    int value ;
    int operation;
    while(true){
        cout<<"\n 1. Insert \n 2. Delete \n 3. Search \n 4. Count nodes \n5.exsit \n";
        cout<<"Enter your task : ";
        cin>> operation;
        switch(operation){
            case 1:
                cout<<"Enter a value:";
                cin>>value;
                root=insertnode(root,value);
                cout<<"Successfully inserted \n";
                break;
            case 2:
               cout<<"Enter a value: ";
               cin>>value;
               root=deleteNode(root,value);
               cout<<"Successfully deleted \n";
               break;
            case 3:
                cout<<"Enter a value: ";
                cin>>value;
                root=search(root,value);
                if(root){
                    cout<<"found \n";

                }else{
                    cout<<"Not found \n";
                }
                break;
            case 4:
               cout<<"Toatl number of elements are :"<<countnode(root);
               break;
           
            case 5:
               cout<<"Exiting....";
               return 0;

            default:
                cout<<"Invalid choice";
        }
    }
}

/*
Short Algorithm for Binary Search Tree (BST)

1. Start the program.
2. Create an empty BST.
3. Display menu for Insert, Delete, Search, Count Nodes, and Exit.

Insert

4. Compare value with root node.
5. Insert smaller value to left subtree and greater value to right subtree.

Delete

6. Search the node to delete.
7. Delete node based on:
    * No child
    * One child
    * Two children

Search

8. Compare target value with current node until found or NULL.

Count Nodes

9. Recursively count left subtree, right subtree, and current node.
10. Repeat operations until user chooses Exit.
11. Stop the program.








*/
/*#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

// Create Node
Node* createnode(int value){
    Node* newNode = new Node();
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert Node
Node* insertnode(Node* root, int value){
    if(root == NULL){
        return createnode(value);
    }

    if(root->val > value){
        root->left = insertnode(root->left, value);
    }
    else{
        root->right = insertnode(root->right, value);
    }

    return root;
}

// Find Minimum Value Node
Node* findmin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// Delete Node
Node* deleteNode(Node* root, int value){

    if(root == NULL){
        return NULL;
    }

    if(root->val < value){
        root->right = deleteNode(root->right, value);
    }
    else if(root->val > value){
        root->left = deleteNode(root->left, value);
    }
    else{

        // No Child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // One Child
        else if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two Children
        else{
            Node* temp = findmin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    return root;
}

// Search Node
Node* search(Node* root, int value){

    while(root != NULL && root->val != value){

        if(root->val > value){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    return root;
}

// Count Nodes
int countnode(Node* root){

    if(root == NULL){
        return 0;
    }

    return 1 + countnode(root->left) + countnode(root->right);
}

// Display BST (Inorder Traversal)
void display(Node* root){

    if(root == NULL){
        return;
    }

    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main(){

    Node* root = NULL;

    int value;
    int operation;

    while(true){

        cout << "\n===== Binary Search Tree =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Count Nodes\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your task : ";
        cin >> operation;

        switch(operation){

            case 1:

                cout << "Enter a value: ";
                cin >> value;

                root = insertnode(root, value);

                cout << "Successfully inserted\n";
                break;

            case 2:

                cout << "Enter a value: ";
                cin >> value;

                root = deleteNode(root, value);

                cout << "Successfully deleted\n";
                break;

            case 3:

                cout << "Enter a value: ";
                cin >> value;

                if(search(root, value)){
                    cout << "Found\n";
                }
                else{
                    cout << "Not Found\n";
                }

                break;

            case 4:

                cout << "Total number of elements are : "
                     << countnode(root);

                break;

            case 5:

                cout << "BST Elements (Inorder Traversal): ";

                if(root == NULL){
                    cout << "Tree is empty";
                }
                else{
                    display(root);
                }

                cout << endl;

                break;

            case 6:

                cout << "Exiting....";
                return 0;

            default:

                cout << "Invalid choice";
        }
    }
}
*/
/*
Short Algorithm for Binary Search Tree (BST)

1. Start the program.
2. Create an empty BST.
3. Display menu for Insert, Delete, Search, Display, Count Nodes, and Exit.

Insert
4. Compare value with root node.
5. Insert smaller value to left subtree and greater value to right subtree.

Delete
6. Search the node to delete.
7. Delete node based on:
   - No child
   - One child
   - Two children

Search
8. Compare target value with current node until found or NULL.

Display
9. Traverse BST using Inorder Traversal:
   Left -> Root -> Right

Count Nodes
10. Recursively count left subtree, right subtree, and current node.

11. Repeat operations until user chooses Exit.
12. Stop the program.
*/