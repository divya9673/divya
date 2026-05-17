#include<iostream>
using namespace std;

class Node
{
public:
    string name;
    int freq;
    Node *left,*right;

    Node(string n,int f)
    {
        name=n;
        freq=f;
        left=right=NULL;
    }
};

Node* insert(Node* root,string name,int freq)
{
    if(root==NULL)
        return new Node(name,freq);

    if(freq > root->freq)
        root->left=insert(root->left,name,freq);
    else
        root->right=insert(root->right,name,freq);

    return root;
}

Node* minValue(Node* root)
{
    while(root->left!=NULL)
        root=root->left;

    return root;
}

Node* deleteNode(Node* root,string name)
{
    if(root==NULL)
        return root;

    if(name < root->name)
        root->left=deleteNode(root->left,name);

    else if(name > root->name)
        root->right=deleteNode(root->right,name);

    else
    {
        if(root->left==NULL)
            return root->right;

        else if(root->right==NULL)
            return root->left;

        Node* temp=minValue(root->right);

        root->name=temp->name;
        root->freq=temp->freq;

        root->right=deleteNode(root->right,temp->name);
    }

    return root;
}

void display(Node* root)
{
    if(root==NULL)
        return;

    display(root->left);

    cout<<root->name<<" "<<root->freq<<endl;

    display(root->right);
}

int main()
{
    Node* root=NULL;

    int choice,freq;
    string name;

    do
    {
        cout<<"\n1.Insert";
        cout<<"\n2.Delete";
        cout<<"\n3.Display";
        cout<<"\n4.Eixt";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter product name: ";
                cin>>name;

                cout<<"Enter frequency: ";
                cin>>freq;

                root=insert(root,name,freq);
                break;

            case 2:
                cout<<"Enter product name: ";
                cin>>name;

                root=deleteNode(root,name);
                break;

            case 3:
                display(root);
                break;
        }

    }while(choice!=4);

    return 0;
}