# CLIDictionary

CLIDictionary is a simple command-line dictionary application written in C++. It allows users to search, add, update, and delete dictionary entries. The dictionary data is stored in a JSON file (dictionary_data.json).


## Prerequisites
To compile and run this application, you will need:
-A C++ compiler (e.g., GCC, Clang, MSVC)
-C++17 Standard Library support


## Compilation
To compile the application, navigate to the CLIDictionary directory and run the following command in your terminal:

' g++ -std=c++17 -o CLIDictionary main.cpp Dictionary.cpp '

This command will compile the main.cpp and Dictionary.cpp files using C++17 standards and create an executable named CLIDictionary.

## Running the Application
Running the Application
After compiling, you can run the application with different commands:

To search for a word:
' ./CLIDictionary search <word> '

To add a new word and its definition:
' ./CLIDictionary add <word> <definition> '

To update an existing word's definition:
' ./CLIDictionary update <word> <new definition> '

To delete a word:
' ./CLIDictionary delete <word> '

## Example Usage
' ./CLIDictionary search apple
./CLIDictionary add orange "A citrus fruit"
./CLIDictionary update apple "A sweet red or green fruit"
./CLIDictionary delete orange
'



