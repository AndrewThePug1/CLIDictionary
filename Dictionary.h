#include <unordered_map>
#include <string>

class Dictionary {
public:
    void addEntry(const std::string& word, const std::string& definition) {
        dictionary[word] = definition;
    }

    std::string searchEntry(const std::string& word) {
        auto it = dictionary.find(word);
        if (it != dictionary.end()) {
            return it->second;
        } else {
            return "Word not found";
        }
    }

    void updateEntry(const std::string& word, const std::string& newDefinition) {
        dictionary[word] = newDefinition;
    }

    void deleteEntry(const std::string& word) {
        dictionary.erase(word);
    }

private:
    std::unordered_map<std::string, std::string> dictionary;
};
