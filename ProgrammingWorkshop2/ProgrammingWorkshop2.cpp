#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <cctype>
using namespace std;

//task 2
string word;
int count = 0;
int numberOfWords = 0;
string filename = "input.txt";
vector<string> wordList; //adds word to vector if occured more than once
map<string, int> wordListMap;
int numberOfSentences;
string test;

string RemovePunctuation(const string & word) 
{
    string newWord;
    
    for (char index : word) {
        if (isalnum(index) || index == '\'') //remove punctuation
        {
            newWord += index;
        }
    }
    return newWord;
}

int Sentences(string fileData)
{
    bool character = false;

    for (char index : fileData)
    {
        if (index == '.' || index == '!' || index == '?') {
            character = false; //is end sentence punctuation
        } else if (!character && !isspace(index)) {
            character = false; //singular space
        } else if (!character && isspace(index)) {
            continue; //ignores multiple spaces.
        }

        if (!character && (index == '.' || index == '!' || index == '?')) {
            numberOfSentences++;
            character = true;
        }
    }
}

int NumberOfWords(string fileData)
{
    for (char index : fileData)
    {
        if (isspace(index))
        {
            numberOfWords++;
        }
    }
    
}

void WordFrequency(const string & content,  vector<string> & words, vector<int> & frequencies) 
{
    std::istringstream iss(content);
    std::string word;
    while (iss >> word) {
        std::string cleanedWord = RemovePunctuation(word);
        
        if (!cleanedWord.empty()) {
            // Check if the word is already in the vector
            auto it = std::find(words.begin(), words.end(), cleanedWord);
            if (it != words.end()) {
                // If the word is already in the vector, update its frequency
                int index = std::distance(words.begin(), it);
                frequencies[index]++;
            } else {
                // If the word is not in the vector, add it and set its frequency to 1
                words.push_back(cleanedWord);
                frequencies.push_back(1);
            }
        }
    }
}

int main()
{
    ifstream ReadFile("input.txt");
    if (!ReadFile) {
        cerr << "Error opening the file." << endl; //cerr outputs to terminal
        return 1;
    }

    string fileContent;
    vector<string> words;
    vector<int> frequencies;
    string line;
    while (getline(ReadFile, line)) {
        fileContent += line + ' ';
    }
    
    Sentences(fileContent);
    NumberOfWords(fileContent);
    cout << "number of sentences is " << numberOfSentences << endl;
    cout << "number of words is " << numberOfWords << endl;
    WordFrequency(fileContent, words, frequencies);

    //displays all words and how many times occured
    for (size_t index = 0; index < words.size(); ++index) {
        cout << words[index] << "  " << frequencies[index] << endl;
    }
}

