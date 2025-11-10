studentNo = int(input("Enter the no. of students:"))
marks = []
for i in range(0, studentNo):
    m = int(input("enter marks:"))
    marks.append(m)

def avg():
    add = 0
    for i in marks:
        if i > 0:
            add += i
    average = add / studentNo
    print("The average of marks is:",(average))
    print("The sum of marks is:",(add))

def absent():
    count = 0
    for i in marks:
        if i < 0:
            count += 1
    print("The number of absent students are:",(count))

def maximum():
    max_val = None
    for i in marks:
        if i > 0:
            if max_val is None or i > max_val:
                max_val = i
    if max_val is not None:
        print("The maximum marks obtained by a student is:",(max_val))
    else:
        print("No students present.")

def minimum():
    min_val = None
    for i in marks:
        if i > 0:
            if min_val is None or i < min_val:
                min_val = i
    if min_val is not None:
        print("The minimum marks obtained by student is:",(min_val))
    else:
        print("No students present.")

def menu():
    while True:
        print("1: Display sum and average of marks:")
        print("2: Display number of absent students:")
        print("3: Display Highest marks obtained:")
        print("4: Display Lowest marks obtained:")
        print("5: Exit")
        
        choice = int(input("Enter your choice: "))
        if choice == 1:
            avg()
        elif choice == 2:
            absent()
        elif choice == 3:
            maximum()
        elif choice == 4:
            minimum()
        elif choice == 5:
            break
        else:
            print("Invalid choice")

menu()
