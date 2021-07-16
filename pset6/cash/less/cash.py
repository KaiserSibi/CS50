def change(change_owed):
    count = 0
    while round(change_owed, 2) >= 0.25:
        change_owed -= 0.25
        count += 1
    while round(change_owed, 2) >= 0.10:
        change_owed -= 0.10
        count += 1
    while round(change_owed, 2) >= 0.05:
        change_owed -= 0.05
        count += 1
    while round(change_owed, 2) >= 0.01:
        change_owed -= 0.01
        count += 1
    return count

def main():
    finished = False
    while finished == False:
        try:
            change_owed = float(input("Change Owed: "))
            if change_owed >= 0:
                results = change(change_owed)
                print(f"{results}")
                finished = True
            else:
                finished = False
        except ValueError:
            finished = False
main()