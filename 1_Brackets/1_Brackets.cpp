#include <fstream>
#include <string>
#include <vector>

using namespace std;

ofstream fout("output.txt");

void calculate(vector<char> str, short int current, short int N, short int countRound, short int countSquare)
{
    if (current != N - 1) {
        short int flagRound = 0, flagSquare = 0;
        bool closedBracket = true;

        for (short int i = current; i >= 0; i--)
        {
            if (closedBracket) {
                if (str[i] == '(')
                    flagRound++;
                else if (str[i] == '[')
                    flagSquare++;
                else if (str[i] == ')')
                    flagRound--;
                else if (str[i] == ']')
                    flagSquare--;
                if (flagRound > 0 || flagSquare > 0)
                    closedBracket = false;
            }
        }
        if (closedBracket)
        {
            str[current + 1] = '(';
            calculate(str, current + 1, N, countRound + 1, countSquare);
            str[current + 1] = '[';
            calculate(str, current + 1, N, countRound, countSquare + 1);
        }
        else
        {
            if (flagRound > 0)
            {
                str[current + 1] = ')';
                calculate(str, current + 1, N, countRound, countSquare);
                if (2 * (countRound + countSquare) < N)
                {
                    str[current + 1] = '(';
                    calculate(str, current + 1, N, countRound + 1, countSquare);
                    str[current + 1] = '[';
                    calculate(str, current + 1, N, countRound, countSquare + 1);
                }
            }
            if (flagSquare > 0)
            {
                str[current + 1] = ']';
                calculate(str, current + 1, N, countRound, countSquare);
                if (2 * (countRound + countSquare) < N)
                {
                    str[current + 1] = '(';
                    calculate(str, current + 1, N, countRound + 1, countSquare);
                    str[current + 1] = '[';
                    calculate(str, current + 1, N, countRound, countSquare + 1);
                }
            }
        }
    }
    else {
        for (short int i = 0; i < N; i++)
            fout << str[i];
        fout << "\n";
    }
}

int main() {
    ifstream input;
    input.open("input.txt");

    short int N;
    input >> N;
    vector<char> vctrBracket(N);

    vctrBracket[0] = '(';
    calculate(vctrBracket, 0, N, 1, 0);

    vctrBracket[0] = '[';
    calculate(vctrBracket, 0, N, 0, 1);

    return 0;
}