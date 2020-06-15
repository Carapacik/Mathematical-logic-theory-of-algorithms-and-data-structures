#include <fstream>
using namespace std;

int main()
{
    ifstream input;
    input.open("input.txt");
    int N,
        K;
    input >> N >> K;

    long* mas = new long[N];
    int temp;
    for (int i = 0; i < N; i++)
    {
        input >> temp;
        mas[i] = temp;
    }

    int border1 = 0, border2 = 10000000, middle, sum;
    do
    {
        sum = 0;
        middle = (border2 + border1) / 2;
        for (int i = 0; i < N; i++)
            sum += mas[i] / middle;

        if (sum < K)
            border2 = middle;
        else
            border1 = middle;
    } while (border2 > border1 + 1);

    ofstream output;
    output.open("output.txt");
    output << border1;

    return 0;
}