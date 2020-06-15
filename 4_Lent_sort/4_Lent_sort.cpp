#include <iostream>
#include <fstream>
using namespace std;

void erraseFile(string filename) {

    fstream file;
    file.open(filename, ios::out);
    file.close();

}

void mege(string string1, string string4, string string2, string string3, int& seria1, int& seria2, int& iteminser) {
    fstream f1, f2, f3, f4;
    string mem1 = "", mem2 = "";
    f1.open(string1, std::ios::out);
    f2.open(string2, std::ios::in);
    f3.open(string3, std::ios::in);
    f4.open(string4, std::ios::out);
    string m1, m2;
    int s1, s2;
    bool check = false;
    int counteros1 = 0, counteros2 = 0;
    string temps = "";
    int loa1 = 0, loa2 = 0;

    while (seria1 != 0) {
        if ((seria1 == 1) && (seria1 > seria2)) {
            while (f2 >> m1) {
                if (check == false) {
                    f1 << " " << m1;
                    mem1 = mem1 + " " + m1;
                }
                else {
                    f4 << " " << m1;
                    mem2 = mem2 + " " + m1;
                }
            }
            if (check == false)
                mem1 = mem1 + " |";
            else
                mem2 = mem2 + " |";
            counteros2++;
            break;
        }
        if ((seria2 == 1) && (seria1 < seria2)) {
            while (f3 >> m2) {
                if (check == false) {
                    f1 << " " << m2;
                    mem1 = mem1 + " " + m2;
                }
                else {
                    f4 << " " << m2;
                    mem2 = mem2 + " " + m2;
                }
            }
            if (check == false)
                mem1 = mem1 + " |";
            else
                mem2 = mem2 + " |";
            counteros1++;
            break;
        }
        if (seria1 == 1 && seria2 == 1) {
            int terpila = 0;
            f2 >> m1;
            f3 >> m2;
            while (terpila != 1) {
                if (terpila == 3) {
                    if (check == false) {
                        f1 << " " << m1;
                        mem1 = mem1 + " " + m1;
                        while (f2 >> m1) {
                            f1 << " " << m1;
                            mem1 = mem1 + " " + m1;
                        }
                        mem1 = mem1 + " |";
                        break;
                    }
                    else {
                        f4 << " " << m1;
                        mem2 = mem2 + " " + m1;
                        while (f2 >> m1) {
                            f4 << " " << m1;
                            mem2 = mem2 + " " + m1;
                        }
                        mem2 = mem2 + " |";
                        break;
                    }
                }
                if (terpila == 2) {
                    if (check == false) {
                        f1 << " " << m2;
                        mem1 = mem1 + " " + m2;
                        while (f3 >> m2) {
                            f1 << " " << m2;
                            mem1 = mem1 + " " + m2;
                        }
                        mem1 = mem1 + " |";
                        break;
                    }
                    else {
                        f4 << " " << m2;
                        mem2 = mem2 + " " + m2;
                        while (f3 >> m2) {
                            f4 << " " << m2;
                            mem2 = mem2 + " " + m2;
                        }
                        mem2 = mem2 + " |";
                        break;
                    }
                }

                s2 = atoi(m2.c_str());
                s1 = atoi(m1.c_str());
                if (check == false) {
                    if (s1 < s2) {
                        f1 << " " << s1;
                        mem1 = mem1 + " " + m1;
                        if (f2 >> m1) {}
                        else
                            terpila = 2;
                    }
                    else {

                        f1 << " " << s2;
                        mem1 = mem1 + " " + m2;
                        if (f3 >> m2) {}
                        else
                            terpila = 3;
                    }
                }
                else {
                    if (s1 < s2) {
                        f4 << " " << s1;
                        mem2 = mem2 + " " + m1;
                        if (f2 >> m1) {}
                        else
                            terpila = 2;
                    }
                    else {
                        f4 << " " << s2;
                        mem2 = mem2 + " " + m2;
                        if (f3 >> m2) {}
                        else {
                            terpila = 3;
                        }
                    }
                }
            }
            counteros2++;
            break;
        }


        f2 >> m1;
        f3 >> m2;
        temps = "";

        if (check == false) {
            while (!f2.eof() || !f3.eof()) {
                if (loa1 == iteminser) {
                    f1 << " " << m2;
                    mem1 = mem1 + " " + m2;
                    loa2++;
                    while (loa2 != iteminser) {
                        f3 >> m2;
                        f1 << " " << m2;
                        loa2++;
                        mem1 = mem1 + " " + m2;
                    }
                    loa1 = 0;
                    loa2 = 0;
                    mem1 = mem1 + " " + "|";
                    counteros1++;
                    break;
                }
                if (loa2 == iteminser) {
                    f1 << " " << m1;
                    mem1 = mem1 + " " + m1;
                    loa1++;
                    while (loa1 != iteminser) {
                        f2 >> m1;
                        f1 << " " << m1;
                        loa1++;
                        mem1 = mem1 + " " + m1;
                    }
                    loa1 = 0;
                    loa2 = 0;
                    mem1 = mem1 + " " + "|";
                    counteros1++;
                    break;
                }
                s2 = atoi(m2.c_str());
                s1 = atoi(m1.c_str());
                if (s1 < s2) {
                    f1 << " " << s1;
                    mem1 = mem1 + " " + m1;
                    loa1++;
                    if (loa1 != iteminser)
                        f2 >> m1;
                }
                else {
                    f1 << " " << s2;
                    mem1 = mem1 + " " + m2;
                    loa2++;
                    if (loa2 != iteminser)
                        f3 >> m2;
                }
            }

            check = true;
            seria1--;
            seria2--;
        }
        else {
            while (!f2.eof() || !f3.eof()) {
                if (loa1 == iteminser) {
                    f4 << " " << m2;
                    mem2 = mem2 + " " + m2;
                    loa2++;
                    while (loa2 != iteminser) {
                        f3 >> m2;
                        f4 << " " << m2;
                        loa2++;
                        mem2 = mem2 + " " + m2;
                    }
                    loa1 = 0;
                    loa2 = 0;
                    mem2 = mem2 + " " + "|";
                    counteros2++;
                    break;
                }
                if (loa2 == iteminser) {
                    f4 << " " << m1;
                    mem2 = mem2 + " " + m1;
                    loa1++;
                    while (loa1 != iteminser) {
                        f2 >> m1;
                        f4 << " " << m1;
                        loa1++;
                        mem2 = mem2 + " " + m1;
                    }
                    loa1 = 0;
                    loa2 = 0;
                    mem2 = mem2 + " " + "|";
                    counteros2++;
                    break;
                }
                s1 = atoi(m1.c_str());
                s2 = atoi(m2.c_str());
                if (s1 < s2) {
                    f4 << " " << s1;
                    mem2 = mem2 + " " + m1;
                    loa1++;
                    if (loa1 != iteminser)
                        f2 >> m1;
                }
                else {
                    f4 << " " << s2;
                    mem2 = mem2 + " " + m2;
                    loa2++;
                    if (loa2 != iteminser)
                        f3 >> m2;
                }
            }
            check = false;
            seria1--;
            seria2--;
        }
    }
    f1.close();
    f2.close();
    f3.close();
    f4.close();

    if (string2 == "F2.txt")
        cout << endl << "F1 : " << mem1 << endl << "F4: " << mem2 << endl;
    else
        cout << endl << "F2 : " << mem1 << endl << "F3: " << mem2 << endl;
    seria1 = counteros2;
    seria2 = counteros1;
}


int main()
{

    string string1 = "F1.txt";
    string string2 = "F2.txt";
    string string3 = "F3.txt";
    string string4 = "F4.txt";
    ifstream in(string1);
    size_t count = 0;
    int x;
    while (in >> x)
        count++;

    fstream f1;
    fstream f2;
    fstream f3;
    fstream f4;
    f1.open(string1, std::ios::in);
    f2.open(string2, std::ios::out);
    f3.open(string3, std::ios::out);

    string strnew1 = "", strnew2 = "";
    int iterator = 0;
    string temp = "";
    while (iterator != count / 2) {
        f1 >> temp;
        strnew1 = strnew1 + " " + temp;
        f2 << " " << temp;
        iterator++;
    }
    f2.close();
    while (iterator != count) {
        f1 >> temp;
        strnew2 = strnew2 + " " + temp;
        f3 << " " << temp;
        iterator++;
    }
    f3.close();
    f1.close();

    cout << "F2: " << strnew1 << endl << "F3: " << strnew2 << endl;


    f1.open(string1, std::ios::out);
    f2.open(string2, std::ios::in);
    f3.open(string3, std::ios::in);
    string g2 = "0", g3 = "0";
    strnew1 = "", strnew2 = "";
    int contik = 0;

    while (!f3.eof() && !f2.eof()) {
        f2 >> g2;
        f3 >> g3;
        contik = 2;
        int g2op = atoi(g2.c_str());
        int g3op = atoi(g3.c_str());
        if (g2op <= g3op) {
            f1 << g2 << " " << g3 << " ";

            strnew1 = strnew1 + " " + g2 + " " + g3 + " |";
        }
        else {
            f1 << g3 << " " << g2 << " ";
            strnew1 = strnew1 + " " + g3 + " " + g2 + " |";
        }
    }
    if (!f3.eof()) {
        if (f2.eof()) {
            f3 >> g3;
            f1 << g3;
            strnew1 = strnew1 + " " + g3 + " |";
        }
    }
    f1.close();
    f2.close();
    f3.close();
    f4.close();

    cout << endl << "F1: " << strnew1 << endl;

    f1.open("F1.txt", std::ios::in);
    f2.open("F2.txt", std::ios::out);
    f3.open("F3.txt", std::ios::out);
    bool check = false;
    int seria1 = 0, seria2 = 0;;
    string temps = "";
    strnew1 = "", strnew2 = "";
    int newmem = 0;
    while (f1 >> temps) {
        if (check == false) {

            f2 << temps << " ";
            strnew1 = strnew1 + " " + temps;
            newmem++;
        }
        else {
            f3 << temps << " ";
            strnew2 = strnew2 + " " + temps;
            newmem++;
        }
        if ((newmem == 2) || (newmem == 1 && f1.eof())) {
            if (check == false) {
                check = true;
                seria1++;
                newmem = 0;
                strnew1 = strnew1 + " " + "|";
            }
            else {
                check = false;
                seria2++;
                newmem = 0;
                strnew2 = strnew2 + " " + "|";
            }
        }
    }
    f1.close();
    f2.close();
    f3.close();

    cout << endl << "F2: " << strnew1 << endl;
    cout << "F3: " << strnew2 << endl;

    bool newbool = false;
    int iteminser = 2;
    while (seria2 != 0) {
        if (newbool == false) {
            mege(string1, string4, string2, string3, seria1, seria2, iteminser);
            newbool = true;
        }
        else {
            mege(string2, string3, string1, string4, seria1, seria2, iteminser);
            newbool = false;
        }
        iteminser = iteminser * 2;
    }

    int tempa = 0;
    if (newbool == false) {
        f2.open(string2, std::ios::in);
        f1.open(string1, std::ios::out);
        while (f2 >> tempa)
            f1 << " " << tempa;
    }
    f1.close();
    f2.close();

    erraseFile(string2);
    erraseFile(string3);
    erraseFile(string4);

    return 0;
}