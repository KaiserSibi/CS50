finished = False
while finished == False:
    try:
        height = int(input("Height: "))
        if height in range(1, 9):
            for a in range(0, height):                     #(a = 1; a <= x; a++)
                for d in range(1, height - a):             #(c = 1; c <= x - a; c++)
                    print(" ", end="")
                for b in range(height - a, height + 1):    #(b = 1; b <= a; b++)
                    print("#", end="")
                print("  ", end="")
                for b in range(height - a, height + 1):    #(b = 1; b <= a; b++)
                    print("#", end="")
                print()
            finished = True
        else:
            finished = False
    except ValueError:
            finished = False