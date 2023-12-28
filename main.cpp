#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


int main() {
    std::string filename = "dictionary_data.json";
    std::ifstream file(filename);
    std::stringstream buffer;

    if(!file) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return 1; 
    }

    // Read the file contents into a string buffer
    buffer << file.rdbuf();
    file.close();


    // Converting string buffer into a string
    std::string jsonData = buffer.str();

    // Output JSON file content to console
    std::cout << "File content:\n" << jsonData << std::endl;

    return 0; // Execution succesful
}
