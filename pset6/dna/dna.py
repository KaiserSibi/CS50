import sys
import csv
import re

def count(string_to_compare, txt_sequence):    #Adapted some of the code from various sources
    p = rf"({string_to_compare})\1*"
    pattern = re.compile(p)
    match = [match for match in pattern.finditer(txt_sequence)]
    max = 0
    for i in range(len(match)):
        if match[i].group().count(string_to_compare) > max:
            max = match[i].group().count(string_to_compare)
    return max

def small_csv(csv_file, text_file):
    with open(csv_file, 'r') as file:
        reader = csv.DictReader(file)
        csv_database = list(reader)
    with open(text_file, 'r') as file2:
        txt_sequence = file2.readline().rstrip("\n")
        AGATC = count("AGATC", txt_sequence)
        AATG = count("AATG", txt_sequence)
        TATC = count("TATC", txt_sequence)
    matched_name = None
    for i in range(len(csv_database)):
        if csv_database[i]["AGATC"] == str(AGATC) and csv_database[i]["AATG"] == str(AATG) and csv_database[i]["TATC"] == str(TATC):
            matched_name = csv_database[i]["name"]
            print(f"{matched_name}")
            break
    if matched_name == None:
        print("No match")

def large_csv(csv_file, text_file):
    with open(csv_file, 'r') as file:
        reader = csv.DictReader(file)
        csv_database = list(reader)
    with open(text_file, 'r') as file2:
        txt_sequence = file2.readline().rstrip("\n")
        AGATC = count("AGATC", txt_sequence)
        TTTTTTCT = count("TTTTTTCT", txt_sequence)
        AATG = count("AATG", txt_sequence)
        TCTAG = count("TCTAG", txt_sequence)
        GATA = count("GATA", txt_sequence)
        TATC = count("TATC", txt_sequence)
        GAAA = count("GAAA", txt_sequence)
        TCTG = count("TCTG", txt_sequence)
    matched_name = None
    for i in range(len(csv_database)):
        if csv_database[i]["AGATC"] == str(AGATC) and csv_database[i]["TTTTTTCT"] == str(TTTTTTCT) and csv_database[i]["AATG"] == str(AATG):
            if csv_database[i]["TCTAG"] == str(TCTAG) and csv_database[i]["GATA"] == str(GATA) and csv_database[i]["TATC"] == str(TATC):
                if csv_database[i]["GAAA"] == str(GAAA) and csv_database[i]["TCTG"] == str(TCTG):
                    matched_name = csv_database[i]["name"]
                    print(f"{matched_name}")
                    break
    if matched_name == None:
        print("No match")

def main():
    if sys.argv[1] == None or sys.argv[2] == None:
        print(f"Usage: python dna.py data.csv sequence.txt")
    else:
        csv_file = sys.argv[1]
        text_file = sys.argv[2]
        if csv_file == "databases/small.csv":
            small_csv(csv_file, text_file)
        elif csv_file == "databases/large.csv":
            large_csv(csv_file, text_file)
main()