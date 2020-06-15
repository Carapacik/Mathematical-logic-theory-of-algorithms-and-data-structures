#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
		return true;
	}
	else {
		return false;
	}
}

string preToPos(string preStrChan) {
	stack<string> st;
	int length = preStrChan.size();
	if (length < 3) {
		string error = "Error: Too few characters";

		return error;
	}
	else {
		if (isOperator(preStrChan[length - 1])) {
			string error = "Error: In position #" + to_string(length);

			return error;
			}
		for (int i = length - 1; i >= 0; i--) {
			if (isOperator(preStrChan[i])) {
				string op1;
				string op2;
				if (st.size() != 0) {
					op1 = st.top();
					st.pop();
				}
				else {
					return "Error: In position #" + to_string(length - i + 1);
				}
				if (st.size() != 0) {
					op2 = st.top();
					st.pop();
				}
				else {
					if (i != 0) {

						return "Error: In position #" + to_string(i + 1);
					}
				}

				string temp = op1 + op2 + preStrChan[i];
				st.push(temp);
			}
			else {
				if (i >= 2) {
					if ((preStrChan[i - 2] == 's' && preStrChan[i - 1] == 'i' && preStrChan[i] == 'n') || (preStrChan[i - 2] == 'c' && preStrChan[i - 1] == 'o' && preStrChan[i] == 's') || (preStrChan[i - 2] == 'e' && preStrChan[i - 1] == 'x' && preStrChan[i] == 'p'))
					{
						if (st.size() != 0) {
							string op3 = st.top();
							st.pop();

							string temp = op3 + preStrChan[i - 2] + preStrChan[i - 1] + preStrChan[i];
							st.push(temp);
							i = i - 2;
						}
						else {
							return "Error: In position #" + to_string(i + 2);
						}
					}
					else {
						st.push(string(1, preStrChan[i]));
					}
				}
				else {
					st.push(string(1, preStrChan[i]));
				}
			}
		}

		string zapas = st.top();
		if (zapas.size() == length) {
			return zapas;
		}
		else {
			string mem = to_string(zapas.size()+1);
			string errorStr = "Error: In position #" + mem;

			return errorStr;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	string nameFile = "";
	cout << "File name: ";
	cin >> nameFile;
	ifstream fin;
	fin.open(nameFile);
	cout << endl;

	if (!fin.is_open()){
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		string preString = "";
		getline(fin, preString);
		cout << preToPos(preString);
	}
	
	return 0;
}