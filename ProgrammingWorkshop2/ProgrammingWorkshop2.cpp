#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;


//task 2
string word;
int count;
int numberOfWords;
int numberOfSentences;
string filename = "input.txt";
vector<int> wordList; //adds word to vector if occured more than once?? keeps count??
string fileContent;

int Sentences(string fileData)
{
    cout << 0;
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
    while (getline(ReadFile, fileContent))
    {
        cout << fileContent;
    }
    ReadFile.close();

    Sentences(fileContent);
    
}

// In this homework, you will implement a program that
// generates a summary of a given document (this could be based on the work from Task 1).
// The summary will include the number of sentences, the number of words, and the
// frequency of each word in the document. For this purpose, you are required to use built-in
// types, vectors/arrays, and control structures to implement this task. The use of functions is
// encouraged. This task will be assessed during the workshop session.. 