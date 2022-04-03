#include <iostream>
#include <string>
#include <fstream>
#include <vector>



std::string finalReplaceWord(std::string originalWord, std::string replaceWord) {
	if (originalWord.at(originalWord.length() - 1) < 64 && originalWord.at(originalWord.length() - 1) > 32) {
		replaceWord.push_back(originalWord.at(originalWord.length() - 1));
	}
	return replaceWord;
}



std::string toLowerCase(std::string input) {
	for (int x = 0; x < input.length(); x++) {
		if(input.at(x) > 64 && input.at(x) < 97){
			input.at(x) = input.at(x) + 32;
		}
	}

	return input;
}


bool checkWord(std::string foundWord, std::string searchWord) {

	if (foundWord.at(foundWord.length() - 1) < 64 && foundWord.at(foundWord.length() - 1) > 32) {
		foundWord.pop_back();
	}

	if (toLowerCase(foundWord) == searchWord) {
		return true;
	}
	return false;
}



int main() {
	std::ifstream inputFile("Text.txt");
	std::string line;
	std::string searchWord;
	std::vector <std::string> vec;
	std::string newWord;

	int wordsPerLine = 10;

	std::cout << "Enter a word you want to replace: ";
	std::cin >> searchWord;
	std::cout << "Enter a word you want to replace \"" << searchWord << "\" with: ";
	std::cin >> newWord;
	newWord = toLowerCase(newWord);

	
	while (inputFile >> line) {
		if (checkWord(line, searchWord)) {
			vec.push_back(finalReplaceWord(line, newWord));
			continue;
		}

		vec.push_back(line);
	}


	std::ofstream outputFile("Text.txt", std::ios_base::trunc);

	for (int x = 0; x < vec.size(); x++) {
		outputFile << vec.at(x);
		outputFile << " "; 

		if (x % (wordsPerLine + 1) == wordsPerLine) {
			outputFile << "\n";
		}

	}

	// Save me
	
	std::cout.flush();
	inputFile.close();
	outputFile.close();

	return 0;
}