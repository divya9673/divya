# include<bits/stdc++.h>
using namespace std;
struct Employee
{
    int id;
    string name;
    float salary;
};
struct Node{
    Employee data;
    Node* next;
};
class Hashtable{
    private:
        int bucket;
        Node** table;

        int hashfunction(int key){
            return key % bucket;
        }
    public:
        Hashtable(int bucketcount){
            bucket=bucketcount;
            table= new Node*[bucket];
            for(int i=0;i<bucket;i++){
                table[i]=NULL;
            }
        }
        void insert(Employee emp){
            int index=hashfunction(emp.id);
            Node* head=table[index];
            while(head!=NULL){
                if(head->data.id==emp.id){
                    head->data=emp;
                    return;
                }
                head=head->next;
            }
            Node* newNode=new Node();
            newNode->data=emp;
            newNode->next=table[index];
            table[index]=newNode;


        }
        void display(){
            for(int i=0;i<bucket;i++){
                cout<<"Index "<<i<<endl;
                Node* head=table[i];
                while(head!=NULL){
                    cout<<"ID: "<<head->data.id<<" Name:"<<head->data.name<<" -> ";
                    head=head->next;
                }
                cout<<"NULL \n";
            }
        }
        Employee* searchnode(int ID){
            int index=hashfunction(ID);
            Node* head=table[index];
            while(head!=NULL){
                if(head->data.id==ID){
                    return & head->data;
                }
                head=head->next;
            }
            return NULL;
        }

};
int main(){
    int size;
    cout<<"enter the size of hash table:";
    cin>>size;
    Hashtable ht(size);
    int choice;
    do{
        cout<<"1.Insert \n2.Display \n3.search \n4.Exit \n";
        cout<<"enter your choice:";
        cin>>choice;
        if(choice==1){
            Employee emp;
            cout<<"Enter id:";
            cin>>emp.id;
            cout<<"enter name:";
            cin>>emp.name;
            cout<<"enter salary:";
            cin>>emp.salary;
            ht.insert(emp);
            cout<<"Insertion completed";
        }else if(choice==2){
            ht.display();
        
        }else if(choice==3){
            int id;
            cout<<"enter id:";
            cin>>id;
            Employee* emp=ht.searchnode(id);
            if(emp!=NULL){
                cout<<"ID "<<emp->id<<" Name:"<<emp->name<<" Salary:"<<emp->salary<<endl;
            }else{
                cout<<"employee not found";
            }
        }


    }
    while(choice!=4);
        cout<<"exit \n";
        return 0;

    

}
/*

Output



enter the size of hash table:5

1.Insert 
2.Display 
3.search 
4.Exit 

enter your choice:1
Enter id:101
enter name:Rahul
enter salary:50000
Insertion completed

enter your choice:1
Enter id:102
enter name:Aman
enter salary:60000
Insertion completed

enter your choice:1
Enter id:106
enter name:Priya
enter salary:55000
Insertion completed

enter your choice:2

Index 0
NULL

Index 1
ID: 106 Name:Priya -> ID: 101 Name:Rahul -> NULL

Index 2
ID: 102 Name:Aman -> NULL

Index 3
NULL

Index 4
NULL

enter your choice:3
enter id:102
ID 102 Name:Aman Salary:60000

enter your choice:3
enter id:200
employee not found

enter your choice:4
exit





Stepwise Algorithm for Hash Table using Chaining

Step 1: Start

Step 2: Initialize Hash Table

1. Create a hash table of fixed size.
2. Initialize all indexes as empty.

Step 3: Define Hash Function

1. Use formula:

index = key % table_size

2. Compute index for storing employee records.

Insertion Operation

Step 4: Insert Employee Record

1. Input:
    * Employee ID
    * Employee Name
    * Salary
2. Compute hash index using hash function.
3. Go to calculated index in hash table.
4. Insert employee record into linked list at that index.
5. Display “Record Inserted”.

⸻

Searching Operation

Step 5: Search Employee Record

1. Input Employee ID.
2. Compute hash index.
3. Traverse linked list at that index.
4. If employee ID matches:
    * Display employee details.
5. Else:
    * Display “Not Found”.
Deletion Operation

Step 6: Delete Employee Record

1. Input Employee ID.
2. Compute hash index.
3. Traverse linked list at that index.
4. If employee found:
    * Delete the node from linked list.
    * Display “Record Deleted”.
5. Else:
    * Display “Not Found”.

Step 7: Stop

* End the program.
*/