#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <unordered_map>

class Dictionary {
public:
    Dictionary() = default;

private:
    std::unordered_map<std::string, std::string> dictionary_;
};

#endif // DICTIONARY_H
