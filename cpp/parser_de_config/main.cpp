#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

int main() {
    std::ifstream file("settings.txt");
    std::vector<std::string> lines;
    std::string line;
    std::map<std::string, std::string> params;

    char delimiter = '=';

    if(!file.is_open()) {
        std::cout << "" << std::endl;
        return -1;
    }

    while(std::getline(file, line)){
        lines.push_back(line);
    }

    file.close();

    bool is_valid = true;

    for(const auto& l:lines){
        if (l.find(delimiter) != std::string::npos) {
            size_t pos = l.find(delimiter);
            std::string left = l.substr(0, pos);
            std::string right = l.substr(pos + 1);

            params[left] = right;
        } else {
            is_valid = false;
            break;
        }
    }

    if(!is_valid) {
        std::cout << "Invalid file!";
        return -1;
    }

    for (const auto& pair : params) {
        std::cout << "Chave: " << pair.first << " | Valor: " << pair.second << "\n";
    }

    std::cout << std::endl << "Done";
    return 0;
}
