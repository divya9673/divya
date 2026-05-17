#include <bits/stdc++.h>
using namespace std;
#define MAX 20
class Node {
    public:
        string key;
        int frequency;
        Node* left;
        Node* right;

        Node(string k, int f) {

            key = k;
            frequency = f;
            left = right = NULL;
        }
};

int cost[MAX][MAX];
int rootTable[MAX][MAX];
class OBST {

private:
    string keys[MAX];
    int freq[MAX];
    int n;

public:

    OBST() {
        n = 0;
    }

    // SORT PRODUCTS
    void sortData() {

        for(int i = 0; i < n - 1; i++) {

            for(int j = i + 1; j < n; j++) {

                if(keys[i] > keys[j]) {

                    swap(keys[i], keys[j]);
                    swap(freq[i], freq[j]);
                }
            }
        }
    }

    // SUM OF FREQUENCIES
    int sum(int i, int j) {

        int s = 0;

        for(int k = i; k <= j; k++) {
            s += freq[k];
        }

        return s;
    }

    // BUILD OBST USING DYNAMIC PROGRAMMING
    void buildOBST() {

        if(n == 0)
            return;

        for(int i = 0; i < n; i++) {

            cost[i][i] = freq[i];
            rootTable[i][i] = i;
        }

        for(int L = 2; L <= n; L++) {

            for(int i = 0; i <= n - L; i++) {

                int j = i + L - 1;

                cost[i][j] = INT_MAX;

                for(int r = i; r <= j; r++) {

                    int left = (r > i) ? cost[i][r - 1] : 0;
                    int right = (r < j) ? cost[r + 1][j] : 0;

                    int total = left + right + sum(i, j);

                    if(total < cost[i][j]) {

                        cost[i][j] = total;
                        rootTable[i][j] = r;
                    }
                }
            }
        }

        cout << "\nOptimal BST Rebuilt Successfully!";
        cout << "\nMinimum Search Cost = " << cost[0][n - 1] << endl;
    }

    // CONSTRUCT TREE
    Node* constructTree(int i, int j) {

        if(i > j)
            return NULL;

        int r = rootTable[i][j];

        Node* root = new Node(keys[r], freq[r]);

        root->left = constructTree(i, r - 1);
        root->right = constructTree(r + 1, j);

        return root;
    }

    // DISPLAY PRODUCTS
    void inorder(Node* root) {

        if(root == NULL)
            return;

        inorder(root->left);

        cout << root->key << " (" << root->frequency << ")  ";

        inorder(root->right);
    }

    void display(Node* root) {

        if(root == NULL) {

            cout << "\nInventory is Empty!\n";
            return;
        }

        cout << "\nProducts in Sorted Order:\n";

        inorder(root);

        cout << endl;
    }

    // INSERT PRODUCT
    Node* insertProduct(Node* root) {

        if(n >= MAX) {

            cout << "\nInventory Full!\n";
            return root;
        }

        string product;
        int frequency;

        cout << "\nEnter product name: ";
        cin >> product;

        cout << "Enter frequency of purchase: ";
        cin >> frequency;

        keys[n] = product;
        freq[n] = frequency;

        n++;

        sortData();

        // AUTOMATIC REBUILD
        buildOBST();

        root = constructTree(0, n - 1);

        cout << "\nProduct Inserted Successfully!\n";

        return root;
    }

    // DELETE PRODUCT
    Node* deleteProduct(Node* root) {

        if(n == 0) {

            cout << "\nInventory is Empty!\n";
            return root;
        }

        string product;

        cout << "\nEnter product name to delete: ";
        cin >> product;

        int pos = -1;

        for(int i = 0; i < n; i++) {

            if(keys[i] == product) {

                pos = i;
                break;
            }
        }

        if(pos == -1) {

            cout << "\nProduct Not Found!\n";
            return root;
        }

        for(int i = pos; i < n - 1; i++) {

            keys[i] = keys[i + 1];
            freq[i] = freq[i + 1];
        }

        n--;

        // AUTOMATIC REBUILD
        if(n > 0) {

            buildOBST();

            root = constructTree(0, n - 1);
        }
        else {

            root = NULL;
        }

        cout << "\nProduct Deleted Successfully!\n";

        return root;
    }
};

int main() {

    OBST obj;

    Node* root = NULL;

    int choice;

    do {

        cout << "\n\n===== ONLINE STORE INVENTORY MENU =====";

        cout << "\n1. Insert Product";
        cout << "\n2. Delete Product";
        cout << "\n3. Display Products";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:

                root = obj.insertProduct(root);
                break;

            case 2:

                root = obj.deleteProduct(root);
                break;

            case 3:

                obj.display(root);
                break;

            case 4:

                cout << "\nExiting Program...\n";
                break;

            default:

                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
