def selectionsort(studentper):
    for i in range(len(studentper)-1):
        small=i
        for j in range(i+1,len(studentper)):
            if studentper[small]>studentper[j]:
                small=j
        if small!=i:
            temp=studentper[i]
            studentper[i]=studentper[small]
            studentper[small]=temp

    print("The final sorted array via selection sort:",studentper)
    
def insertionsort(arr,l):
    for i in range (1,l):
        temp=arr[i]
        j=i-1
        while j>=0 and temp<=arr[j]:
            arr[j+1]=arr[j]
            j=j-1
        arr[j+1]=temp
    print( f"The sorted array via insertion sort:{arr}")

def bubblesort(studentper):
    for i in range(len(studentper)):
        for j in range(len(studentper)-1):
            if studentper[j]>studentper[j+1]:
                temp=studentper[j]
                studentper[j]=studentper[j+1]
                studentper[j+1]=temp    
    print("Final sorted array via bubble sort:",studentper)
    
def quicksort(arr,start,end):
    if start<end :
        pivotindex=partitionfun(arr,start,end)
        quicksort(arr,start,pivotindex-1)
        quicksort(arr,pivotindex+1,end)
    return arr

def partitionfun(arr,start,end):
    pivot=arr[start]
    lb=start+1
    ub=end
    while True:
        while lb<=ub and arr[lb]<=pivot:
            lb+=1
             
        while lb<=ub and arr[ub]>=pivot:
            ub-=1
            
        if lb<=ub:
            arr[ub],arr[lb]=arr[lb],arr[ub]
        else:
            break
    arr[start],arr[ub]=arr[ub],arr[start]
    return ub

studentper=[]
size=int (input("Enter the number of students:"))
for i in range (size):
    percentage=float(input("Enter percentage of a student:"))
    studentper.append(percentage)

print("The unsorted array: ",studentper)
def menu():
    while True:
        print("1:Display Selection sort:")
        print("2:Display Insertion sort:")
        print("3:Display Bubble sort:")
        print("4:Display Quick sort:")

        choice=int(input("enter your choice:"))
        if choice==1:
            selectionsort(studentper)
            
        elif choice==2:
            insertionsort(studentper,size)
        elif choice==3:
            bubblesort(studentper)
            
        elif choice==4:
            sort=quicksort(studentper,0,len(studentper)-1)
            print("Sorted array:",sort)
        

menu()
