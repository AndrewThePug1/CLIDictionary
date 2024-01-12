#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include "Dictionary.h"

std::string readFileContent(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;

    if (!file) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return "";
    }

    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

void loadDictionaryFromJson(Dictionary& dict, const std::string& jsonData) {
    std::regex wordRegex("\"(\\w+)\":\\s*\"([^\"]+)\"");
    std::smatch matches;
    std::string::const_iterator searchStart(jsonData.cbegin());

    while (std::regex_search(searchStart, jsonData.cend(), matches, wordRegex)) {
        dict.addEntry(matches[1].str(), matches[2].str());
        searchStart = matches.suffix().first;
    }
}

void writeDictionaryToJson(const Dictionary& dict, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
        return;
    }

    outFile << "{\n";
    const auto& entries = dict.getEntries();
    for (auto it = entries.begin(); it != entries.end(); ++it) {
        outFile << "  \"" << it->first << "\": \"" << it->second << "\"";
        if (std::next(it) != entries.end()) outFile << ",";
        outFile << "\n";
    }
    outFile << "}\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./CLIDictionary [search|add|update|delete] [word] [definition(for add/update)]\n";
        return 1;
    }

    Dictionary myDictionary;
    std::string jsonData = readFileContent("dictionary_data.json");
    loadDictionaryFromJson(myDictionary, jsonData);

    std::string command = argv[1];

    if (command == "search") {
        if (argc != 3) {
            std::cerr << "Usage: ./CLIDictionary search [word]\n";
            return 1;
        }
        std::string word = argv[2];
        std::cout << "Definition: " << myDictionary.searchEntry(word) << std::endl;
    } else if (command == "add" || command == "update") {
        if (argc != 4) {
            std::cerr << "Usage: ./CLIDictionary " << command << " [word] [definition]\n";
            return 1;
        }
        std::string word = argv[2];
        std::string definition = argv[3];
        if (command == "add") {
            myDictionary.addEntry(word, definition);
        } else {
            myDictionary.updateEntry(word, definition);
        }
        std::cout << "Entry " << command << "ed." << std::endl;
        writeDictionaryToJson(myDictionary, "dictionary_data.json");
    } else if (command == "delete") {
        if (argc != 3) {
            std::cerr << "Usage: ./CLIDictionary delete [word]\n";
            return 1;
        }
        std::string word = argv[2];
        myDictionary.deleteEntry(word);
        std::cout << "Entry deleted." << std::endl;
        writeDictionaryToJson(myDictionary, "dictionary_data.json");
    } else {
        std::cerr << "Invalid command. Use search, add, update, or delete." << std::endl;
        return 1;
    }

    return 0;
}
