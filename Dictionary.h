#include <unordered_map>
#include <string>

class Dictionary {
public:
    // Adds a word and its definition to the dictionary.
    void addEntry(const std::string& word, const std::string& definition) {
        dictionary[word] = definition;
    }

    // Searches for a word and returns its definition.
    std::string searchEntry(const std::string& word) const {
        auto it = dictionary.find(word);
        if (it != dictionary.end()) {
            return it->second;
        } else {
            return "Word not found";
        }
    }

    // Updates the definition of an existing word.
    void updateEntry(const std::string& word, const std::string& newDefinition) {
        dictionary[word] = newDefinition;
    }

    // Deletes a word from the dictionary.
    void deleteEntry(const std::string& word) {
        dictionary.erase(word);
    }

    // Returns all entries in the dictionary.
    const std::unordered_map<std::string, std::string>& getEntries() const {
        return dictionary;
    }

private:
    std::unordered_map<std::string, std::string> dictionary;
};