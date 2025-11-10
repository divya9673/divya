def linearseacrh(arr):
    x=int(input("enter an unique id of an employee which you want to find:"))
    c=0
    for i in range (len(arr)):
        k=0
        if arr[i]==x:
            k+=1
            break
        else:
            c+=1


    if k==1:
        print("Target found at an index (linear search):",c)
    else:
        print("Target not Found")


def binarysearch(arr):
    arr.sort()
    print(f"Sorted array for binary search {arr}")
    low=0
    high=len(arr)-1
    Target=int(input("Enter an unique id of a Target employee:"))
    c=0

    while low<=high:
        mid=(low+high)//2
        if arr[mid]==Target:
            c=1
            break
        elif arr[mid]>Target:
            high=mid-1
        else:
            low=mid+1

    if c==1:
        print("Target found at position (binary search):",mid)
    else:
        print("Target not found")
    
        
size=int (input("Enter the number of employee:"))
arr=[]
for i in range (size):
    e=int(input("Enter unique id of employee:"))
    arr.append(e)

linearseacrh(arr)
binarysearch(arr)

