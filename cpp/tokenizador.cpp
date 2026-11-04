#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::string> lines;

int read_file(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return 0;
}

void tokenize(const std::vector<std::string>& lines_to_process) {
    for (const auto& l : lines_to_process) {
        std::istringstream iss(l);
        std::string word;
        while (iss >> word) {
            std::cout << "`" << word << "`\n";
        }
    }
}

int main() {
    std::string filename = "exemplo.txt";

    if (read_file(filename) == 0) {
        tokenize(lines);
    } else {
        return -1;
    }

    return 0;
}
