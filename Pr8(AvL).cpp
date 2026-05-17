#include<iostream>
using namespace std;


struct Node{
    string name;
    int score,h;
    Node *left,*right;
};


int height(Node *n){
    return n?n->h:0;
}


int balance(Node *n){
    return n?height(n->left)-height(n->right):0;
}
Node* newNode(string name,int score){
    Node *n=new Node();
    n->name=name;
    n->score=score;
    n->h=1;
    n->left=n->right=NULL;
    return n;
}

Node* rightRotate(Node *y){
    Node *x=y->left;
    Node *t=x->right;

    x->right=y;
    y->left=t;

    y->h=max(height(y->left),height(y->right))+1;
    x->h=max(height(x->left),height(x->right))+1;

    return x;
}

Node* leftRotate(Node *x){
    Node *y=x->right;
    Node *t=y->left;

    y->left=x;
    x->right=t;

    x->h=max(height(x->left),height(x->right))+1;
    y->h=max(height(y->left),height(y->right))+1;

    return y;
}

Node* insert(Node *root,string name,int score){

    if(!root)
        return newNode(name,score);

    if(score<root->score)
        root->left=insert(root->left,name,score);
    else
        root->right=insert(root->right,name,score);

    root->h=max(height(root->left),height(root->right))+1;

    int b=balance(root);

    if(b>1&&score<root->left->score)
        return rightRotate(root);

    if(b<-1&&score>root->right->score)
        return leftRotate(root);

    if(b>1&&score>root->left->score){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }

    if(b<-1&&score<root->right->score){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minNode(Node *root){
    while(root->left)
        root=root->left;
    return root;
}

Node* deleteNode(Node *root,int score){

    if(!root)
        return root;

    if(score<root->score)
        root->left=deleteNode(root->left,score);

    else if(score>root->score)
        root->right=deleteNode(root->right,score);

    else{

        if(!root->left||!root->right){

            Node *temp=root->left?root->left:root->right;

            if(!temp)
                return NULL;

            *root=*temp;
            delete temp;
        }

        else{

            Node *temp=minNode(root->right);

            root->score=temp->score;
            root->name=temp->name;

            root->right=deleteNode(root->right,temp->score);
        }
    }

    root->h=max(height(root->left),height(root->right))+1;

    int b=balance(root);

    if(b>1&&balance(root->left)>=0)
        return rightRotate(root);

    if(b>1&&balance(root->left)<0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }

    if(b<-1&&balance(root->right)<=0)
        return leftRotate(root);

    if(b<-1&&balance(root->right)>0){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void display(Node *root){

    if(root){

        display(root->right);

        cout<<root->name<<" : "<<root->score<<endl;

        display(root->left);
    }
}



int main(){

    Node *root=NULL;
    int choice,score;
    string name;

    while(true){

        cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Exsit\n";
        cin>>choice;

        if(choice==1){

            cout<<"Enter name and score: ";
            cin>>name>>score;

            root=insert(root,name,score);
        }


        else if(choice==2){

            cout<<"Enter score to delete: ";
            cin>>score;

            root=deleteNode(root,score);
        }


        else if(choice==3){

            cout<<"\nLeaderboard:\n";
            display(root);
        }


        else
            break;


    
    }

    return 0;


}










