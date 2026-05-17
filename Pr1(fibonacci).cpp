# include <bits/stdc++.h>
using namespace std;
class library{
    private:
    vector<string>books;
    public:
    library(){
        books={"DSA","AI","Design and Analysis of Algorithm","Project Management","R.D.Sharma","System Design"
        };
        sort(books.begin(),books.end());

    }
    int fibsearch(string target){
        int n=books.size();
        int f2=0;
        int f1=1;
        int fm=f2+f1;
        while(fm<n){
            f2=f1;
            f1=fm;
            fm=f2+f1;
        }
        int offset=-1;
        while(fm>1){
            int i=min(offset+f2,n-1);
            if(books[i]<target){
                fm=f1;
                f1=f2;
                f2=fm-f1;
                offset=i;
            }else if(books[i]>target){
                fm=f2;
                f1=f1-f2;
                f2=fm-f1;
            }else{
                return i;
            }
        }
        if(f1 && books[offset+1]==target){
            return offset+1;
        }
        return -1;

    }
    void displaybook(){
        cout<<"List of Books:\n";
        for(int i=0;i<books.size();i++){
            cout<<i<<":"<<books[i]<<endl;
        }
    }
};
int main(){
    library lib;
    string findbook;
    cout<<"Enter the name of book to find:";
    getline(cin, findbook);
    lib.displaybook();
    int result=lib.fibsearch(findbook);
    cout<<"searching book:"<<findbook<<endl;
    if(result!=-1){
        cout<<"Book found at index:"<<result<<endl;
    }else{
        cout<<"Book does not found";
    }
    return 0;
    
}