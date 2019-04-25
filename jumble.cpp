#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// this function rearranged the characters in a string
//  so that they are sorted (according to their ASCII value).
void ssort(std::string &s) {
    std::sort(s.begin(), s.end());
}

int main(int argc, char *argv[]){
    // the variable anagram is an unordered_map
    // the keys are strings and the values(anagrams for the keys) are a vector of strings.
    std::unordered_map<std::string, std::vector<std::string>> anagram;
    std::ifstream file;
    std::string word;

    if(argc != 2) {
        std::cout << "usage:  ./freq <filename>\n";
        std::cout << "goodbye\n";
        return 1;
    }

    file.open(argv[1], std::ios::in);

    if(!file.is_open()){
    std::cout << "Error: could not open file '" <<
        argv[1] << "'\n";
    std::cout << "goodbye\n";
    return 1;
    }

    std::cout << "reading input file...\n";
    std::string sorted_word;
    int num_words = 0;
    int num_classes = 0;
    int size_of_largest_class = 0;
    std::string largest_class_key;

    while(file >> word) { 
        num_words++;
        sorted_word = word;
        ssort(sorted_word);
        if(anagram.count(sorted_word) == 0){
            anagram[sorted_word].push_back(word);
            num_classes++;
            if(anagram[sorted_word].size() > size_of_largest_class){
                size_of_largest_class = anagram[sorted_word].size();
                largest_class_key = sorted_word;
            }
        }
        else {
            anagram[sorted_word].push_back(word);
            if(anagram[sorted_word].size() > size_of_largest_class){
                size_of_largest_class = anagram[sorted_word].size();
                largest_class_key = sorted_word;
            }
        }
    }

    std::cout << "Enter a word and I will tell you all the anagrams for that word\n";
    std::cout << "When you are done, type ctrl-d (ctrl-z on windows)\n\n";
    std::cout << "> ";
    int i;
    std::vector<std::string> printAnagrams;

    while(std::cin >> word) { 
        ssort(word);
        if(anagram.count(word)==0) {
            std::cout << "No Anagrams Found... Try again\n";
        }
        else {
            std::cout << "English Anagrams Found:\n";
            printAnagrams = anagram[word];
            for(i = 0; i<printAnagrams.size(); i++){
                std::cout << "  "<< printAnagrams[i] << "\n";
            }
        }
        std::cout << "\n" << "> ";
    }

    // user has quit.  Let's dump the map contents
    std::cout << "REPORT:\n\n";
    std::cout << " num_words             :   " << num_words << "\n";
    std::cout << " num_classes           :   " << num_classes << "\n";
    std::cout << " size_of_largest_class :   " << size_of_largest_class << "\n";
    std::cout << " largest_class_key     :   " << largest_class_key << "\n";
    std::cout << " members of largest class:\n";
    printAnagrams = anagram[largest_class_key];
    for(i = 0; i<printAnagrams.size(); i++){
        std::cout << "  "<< printAnagrams[i] << "\n";
    }
    return 0;
}