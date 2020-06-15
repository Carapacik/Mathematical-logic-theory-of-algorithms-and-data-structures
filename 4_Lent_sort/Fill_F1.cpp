#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main()
{
    int count = 0;
    ofstream file;
    file.open("F1.txt");
    cin >> count;
    while (count != 0) {
        file << rand() % 1000 + 1 << " ";
        count--;

    }
    file.close();
    return 0;
}