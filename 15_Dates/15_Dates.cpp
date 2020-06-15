#include <fstream>
using namespace std;

struct date {
    short int day;
    short int month;
};

date win[] = {
    {28, 1},
    {30, 3},
    {31, 1}
};

date lose[]{
    {30, 1},
    {31, 3}
};

short int whoWin(date date) {
    for (auto item : win)
        if (item.month == date.month && item.day == date.day)
            return 1;
    for (auto item : lose)
        if (item.month == date.month && item.day == date.day)
            return 2;
    if (date.month % 3 == 0 && date.day % 3 == 0)
        return 2;
    else if (date.month % 3 == 1 && date.day % 3 == 1)
        return 2;
    else if (date.month % 3 == 2 && date.day % 3 == 2)
        return 2;

    return 1;
}

int main()
{
    ifstream input;
    input.open("input.txt");
    short int N;
    input >> N;

    ofstream output;
    output.open("output.txt");
    date date;
    for (short int i = 0; i < N; i++) {
        input >> date.day
            >> date.month;
        output << whoWin(date)
            << " ";
    }

    return 0;
}