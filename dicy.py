from random import randint

def spots(x):
    if x==1:
        print("\n*")
    elif x==2:
        print("\n*")
        print("*")
    elif x==3:
        print("\n*")
        print("*")
        print("*")
    elif x==4:
        print("\n*    *")
        print("*    *")
    elif x==5:
        print("\n*    *")
        print("  *  ")
        print("*    *")
    elif x==6:
        print("\n*    *")
        print("*    *")
        print("*    *")
    else:
        print("\nError")

def roll():
    return randint(1,7)

def main():
    for i in range(0,2):
        spots(roll())

main()