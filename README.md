# Jumble

This project usues a clever application of hash tables to solve "word jumble" puzzles. You have probably seen these puzzles in the newspaper. The program is called Jumble and requires a single command-line argument specifying a dictionary file.

./jumble dictionary-small.txt OR ./jumble dictionary-big.txt

After the program sets up its internal data structures, it enters a simple interactive loop which behasves as follows: 

 - The user either enters a string of characters (jumbled version) or types ctrl-d to terminate the interactive loop.
 
 - If the user enters a string, a list of all English words in the given dictionary that are anagrams of the user input in printed.  if there are no such english words in the dictionary, the program prints "no matches". 
 
 - Whe the user terminates the interactive loop, the program produces a report with the following information.
 The number of words read from the input file. The number of "equivalence-classes". The size of the largest equivalence class. The key associated with the largest equivalence class. The members of the largest equivalence class.
