#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::string word = "null (not been assigned)";
    int count = 0;
    int numberOfWords = 0;
    std::string filename = "input.txt"; // Replace with your file's path
    std::vector<int> wordList;
    std::string fileContent;

    // Read content from the file
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::stringstream documentStream;
    documentStream << inputFile.rdbuf();
    fileContent = documentStream.str();

    // Tokenize the document into words
    std::vector<std::string> words;
    std::istringstream iss(fileContent);
    std::string token;
    while (iss >> token) {
        // Remove punctuation and convert to lowercase
        for (char& c : token) {
            if (std::ispunct(c)) {
                c = ' ';
            } else {
                c = std::tolower(c);
            }
        }
        words.push_back(token);
    }

    // Count the number of sentences
    size_t numSentences = std::count(fileContent.begin(), fileContent.end(), '.');

    // Count the number of words
    numberOfWords = words.size();

    // Calculate the frequency of each word and keep count if it occurs more than once
    std::map<std::string, size_t> wordFrequency;
    for (const std::string& w : words) {
        if (w != "null (not been assigned)") {
            wordFrequency[w]++;
            if (wordFrequency[w] > 1) {
                wordList.push_back(wordFrequency[w]);
            }
        }
    }

    // Print the summary
    std::cout << "Number of sentences: " << numSentences << std::endl;
    std::cout << "Number of words: " << numberOfWords << std::endl;
    std::cout << "Word frequency:" << std::endl;
    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Words occurring more than once:" << std::endl;
    for (const int& freq : wordList) {
        std::cout << freq << " times" << std::endl;
    }

    inputFile.close();
    return 0;
}
