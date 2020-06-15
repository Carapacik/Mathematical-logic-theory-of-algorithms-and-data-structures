#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct triangle {
    int number;
    string destination;
    long sum;
};

int main()
{
    ifstream input;
    input.open("input.txt");
    short int N;
    input >> N;

    vector<vector<triangle>> vect(N + 1);
    vect[0].resize(1);
    for (short int i = 1; i <= N; i++)
    {
        int temp;
        vect[i].resize(i);
        for (short int j = 0; j < i; j++) {
            input >> temp;
            vect[i][j].number = temp;
            vect[i][j].destination = "";
            vect[i][j].sum = 0;
        }
    }

    for (short int i = N; i >= 1; i--) {
        for (short int j = i - 1; j >= 0; j--) {
            if (j != i - 1 || i == 1) {
                if (vect[i - 1][j].sum <= vect[i][j].number + vect[i][j].sum) {
                    vect[i - 1][j].sum = vect[i][j].number + vect[i][j].sum;
                    vect[i - 1][j].destination = to_string(vect[i][j].number) + " " + vect[i][j].destination;
                }
            }
            if (j != 0) {
                if (vect[i - 1][j - 1].sum <= vect[i][j].number + vect[i][j].sum) {
                    vect[i - 1][j - 1].sum = vect[i][j].number + vect[i][j].sum;
                    vect[i - 1][j - 1].destination = to_string(vect[i][j].number) + " " + vect[i][j].destination;
                }
            }
        }
    }

    ofstream output;
    output.open("output.txt");
    output << vect[0][0].sum << endl << vect[0][0].destination << endl;
    return 0;
}