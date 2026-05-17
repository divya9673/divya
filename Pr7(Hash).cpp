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
