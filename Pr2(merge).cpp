# include <bits/stdc++.h>
using namespace std;
struct Student{
    int rollno;
    string name;
    int marks;

};
void merge(vector<Student>& stud, int low,int mid,int high){
    vector<Student>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(stud[left].marks <= stud[right].marks){
            temp.push_back(stud[left]);
            left++;
        }else{
            temp.push_back(stud[right]);
            right++;
        }

    }
    while(left<=mid){
        temp.push_back(stud[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(stud[left]);
        right++;
    }
    for(int i=low;i<=high;i++){
        stud[i]=temp[i-low];
    }

}
void mergesort(vector<Student>& stud,int low , int high){
    if(low==high)return ;
    int mid=(low+high)/2;
    mergesort(stud,low,mid);
    mergesort(stud,mid+1,high);
    merge(stud,low,mid,high);
}
void display(vector<Student>&  stud){
    cout<<"\n Sorted Students Records:\n";
    cout<<"Rollno \t Name \t Marks \n";
    for(auto s:stud){
        cout<<s.rollno<<"\t"<<s.name<<"\t"<<s.marks<<endl;
    }

}
int main(){
    int n;
    cout<<"Enter the number of students:";
    cin>>n;
    vector<Student>student(n);
    for(int i=0;i<n;i++){
        cout<<"Enter Students Details"<<i+1<<": \n";
        cout<<"Rollno:";
        cin>>student[i].rollno;
        cout<<"Name:";
        cin>>student[i].name;
        cout<<"Marks:";
        cin>>student[i].marks;
    }
    mergesort(student,0,n-1);
    display(student);
    return 0;   
}