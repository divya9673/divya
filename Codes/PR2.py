rows=int(input("enter number of rows for matrix 1:"))
columns=int(input("enter number of columns for matrix 1:"))
M=[]
for i in range(rows):
    a=[]
    for j in range (columns):
        a.append(int(input("element:")))
    M.append(a)
# print(M)
for i in range (rows):
    for j in range(columns):
        print(M[i][j],end=" ")
    print( )
rows=int(input("enter number of rows for matrix 2:"))
columns=int(input("enter number of columns for matrix 2:"))

M2=[]
for i in range (rows):
    r=[]
    for j in range (columns):
        r.append(int(input("elements of M2:")))
    M2.append(r)

for i in range (rows):
    for j in range (columns):
        print(M2[i][j], end=" ")
    print ()

def add():
    for i in range (rows):
        for j in range (columns):
            print(M[i][j]+M2[i][j],end=" ")
            
        print()

def sub():
    for i in range (rows):
        for j in range (columns):
            print(M[i][j]-M2[i][j],end=" ")
        print()


def trans():
    print("Transpose of Matrix M:")
    for i in range(rows):
        for j in range(columns):
            print(M[j][i], end=" ")
        print()

    print("Transpose of Matrix M2:")
    for i in range(rows):
        for j in range(columns):
            print(M2[j][i], end=" ")
        print()

def mult():
    resultmat=[]
    prod=0
    
    for i in range(rows):
        r=[]
        for j in range(columns):
            for k in range (2):
                prod+=M[i][k]*M2[k][j]
            r.append(prod)
        resultmat.append(r)
    for i in range(rows):
        for j in range (columns):
            print(resultmat[i][j],end=' ')
        print()
        
def menu():
    while True:
        print("option 1 is for addition of two matrix")
        print("option 2 is for subtraction of two matrix")
        print("option 3 is for transpose of a matrix")
        print("option 4 is for multiplication of a matrix")

        option=int(input("enter your option:"))
        if option==1:
            add()
        
        elif option==2:
            sub()
        elif option==3:
            trans()
        elif option==4:
            mult()
menu()
