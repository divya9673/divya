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

/*
ALGORITHM:
Fibonacci Search
Step 1: Start
Step 2: Read the number of books n
Step 3: Store book titles in a sorted array
Step 4: Initialize Fibonacci numbers
● fibMm2 = 0
● fibMm1 = 1
● fibM = fibMm1 + fibMm2
Step 5: Generate Fibonacci number greater than or equal to n
Step 6: Set offset = -1
Step 7: While fibM > 1
● Calculate index i = min(offset + fibMm2, n-1)
● If book found at index i, stop
● If target is greater, move to right subarray
● If target is smaller, move to left subarray
Step 8: If found, display position
Step 9: Else display “Book not found”
Step 10: Stop
TIME COMPLEXITY
● Best Case: O(log n)
● Average Case: O(log n)
● Worst Case: O(log n)
*/