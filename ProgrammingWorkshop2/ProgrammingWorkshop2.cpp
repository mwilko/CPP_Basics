#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;


//task 2
string word = "null (not been assigned)";
int count = 0;
int numberOfWords = 0;
string filename = "input.txt";
vector<int> wordList; //adds word to vector if occured more than once?? keeps count??
string fileContent;
int numberOfSentences;

int Sentences(string fileData)
{
    bool character = false;
    int counter = 0;

    cout << fileData;

    for (char index : fileData)
    {
        counter++;
        if (index == '.' || index == '!' || index == '?') {
            character = false; //is end sentence punctuation
        } else if (!character && !isspace(index)) {
            character = false; //singular space
        } else if (!character && isspace(index)) {
            continue; //ignores multiple spaces.
        }

        if (!character && (index == '.' || index == '!' || index == '?')) {
            numberOfSentences++;
            cout << "LOGGED AS END SENTENCE: " << index << endl;
            character = true;
        }
        cout << "Counter:" << counter << " Index: " << index << endl;
    }
    cout << "Number of sentences: " << numberOfSentences << endl;
}
int NumberOfWords(string fileData)
{
    cout << 0;


}
int WordFrequency(string fileData)
{
    cout << 0;

}

int main()
{
    ifstream ReadFile(filename);
    while (getline(ReadFile, fileContent)) //writes file content to string
    {
        //cout << fileContent;
        Sentences(fileContent);
    }
    ReadFile.close();
}

// In this homework, you will implement a program that
// generates a summary of a given document (this could be based on the work from Task 1).
// The summary will include the number of sentences, the number of words, and the
// frequency of each word in the document. For this purpose, you are required to use built-in
// types, vectors/arrays, and control structures to implement this task. The use of functions is
// encouraged. This task will be assessed during the workshop session.. 