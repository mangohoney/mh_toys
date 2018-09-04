#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

int main()
{
    std::ifstream input("exp.txt");
    std::ofstream output("exp2.txt");
    std::ofstream output2("expb.txt");
    std::string line, word;
    std::vector<int> v = {};
    int cou = 2;
    int car = 0;
    while (getline(input, line)) {
        std::istringstream record(line);
        while (record >> word) {
            if (car == 2) {
                int temp = round(std::stoi(word) / 1.3);
                output << temp << ", ";
                v.push_back(temp);
                car = 0;
                ++cou;
                break;
            }
            if (word == std::to_string(cou)) {
                ++car;
            }
        }
    }
    output2 << v[0] << ", ";
    for (int i = 1; i < v.size(); ++i) {
        output2 << v[i] - v[i - 1] << ", ";
    }
    return 0;
}
