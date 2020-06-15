#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string str = "";
    long long permutations = 0; // количество перестановок
    long trigger = 0; // закрывающий сч
    long long charactersToDifferences = 0; // сумма символов до закрывающего сч = 0 в разные моменты
    long  k = 0; // Количество )( с закрывающим сч = 0
    long symbolsForNextStation = 0; // Количество символов от )( до следующего )(
    vector<long> vec; // Вектор с числами для подсчёта charactersToDifferences
    vector<long> station; // Станции с триггером 0

    outputFile.open("output.txt");
    inputFile.open("input.txt");
    getline(inputFile, str);
    long len = str.length();

    for (long i = 0; i < len; i++) {
        if (str[i] == '(') {
            trigger++;
        }
        else {
            trigger--;
        }
        if (trigger == 0) {
            if (i != len - 1) {
                k++;
                vec.push_back(i + 1);
            }
            if (vec.size() > 1) {
                station.push_back(symbolsForNextStation);
            }
            symbolsForNextStation = 0;
        }
        symbolsForNextStation++;
    }

    for (long i = 0; i < k; i++) {
        if (k == 1) {
            charactersToDifferences += vec[i] * (len - vec[i]);
        }
        else {
            charactersToDifferences += vec[i] * station[i];
        }
    }

    permutations = (len + 1) * len + 1 - charactersToDifferences;
    cout << permutations;
    outputFile << permutations;

    return 0;
}