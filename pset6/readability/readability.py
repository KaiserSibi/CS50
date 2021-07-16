def charactercounter(textsample):
    char_counter = 0
    for a in range(len(textsample)):
        if textsample[a].isalpha():
            char_counter += 1
    return char_counter

def wordcounter(textsample):
    word_counter = 1
    for a in range(len(textsample)):
        if textsample[a] == ' ' or textsample[a] == '\n' or textsample[a] == '\t':
            word_counter += 1
    return word_counter

def sentencecounter(textsample):
    sen_counter = 0
    for a in range(len(textsample)):
        if textsample[a] == '.' or textsample[a] == '!' or textsample[a] == '?':
            sen_counter += 1
    return sen_counter

def indexer(characters, words, sentences):
    avg_words = round(float((characters / words) * 100), 2)
    avg_sents = round(float((sentences / words) * 100), 2)
    rIndex = round((float)(0.0588 * avg_words - 0.296 * avg_sents - 15.8))
    #print(f"{avg_words} -- {avg_sents} -- {rIndex}")
    if rIndex > 10:
        print("Grade 16+")
    elif rIndex > 9:
        print("Grade 10")
    elif rIndex > 8:
        print("Grade 9")
    elif rIndex > 7:
        print("Grade 8")
    elif rIndex > 6:
        print("Grade 7")
    elif rIndex > 5:
        print("Grade 6")
    elif rIndex > 4:
        print("Grade 5")
    elif rIndex > 3:
        print("Grade 4")
    elif rIndex > 2:
        print("Grade 3")
    elif rIndex > 1:
        print("Grade 2")
    elif rIndex > 0:
        print("Grade 1")
    elif rIndex < 0:
        print("Before Grade 1")
    else:
        print("Unable to process results!")
        return 1
    return 0

def main():
    textsample = input("Enter text sample: ")
    characters = charactercounter(textsample)
    words = wordcounter(textsample)
    sentences = sentencecounter(textsample)
    print(f"Category    | Amount")
    print(f"___________________________________")
    print(f"Letters     | {characters}")
    print(f"Word(s)     | {words}")
    print(f"Sentence(s) | {sentences}")
    print(f"-----------------------------------")
    indexed = indexer(characters, words, sentences)
main()