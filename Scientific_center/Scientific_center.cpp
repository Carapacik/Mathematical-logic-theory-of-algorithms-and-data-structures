#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <sstream>
using namespace std;

struct lol {
	int wt, vertex, dst;
	string ima;
};

struct Vertex {
	int src, weight;
	string name;
};

struct Edge {
	int src, dst;
};

class Graph
{
public:
	vector<vector<Edge>> adjPath;
	vector<vector<Vertex>> adjVert;
	Graph(vector<Edge> const& edges, vector<Vertex> const& vert, int cost)
	{
		adjPath.resize(cost);
		for (Edge const& edge : edges) {
			adjPath[edge.src].push_back(edge);
		}
		adjVert.resize(cost);
		for (Vertex const& vers : vert) {
			adjVert[vers.src].push_back(vers);
		}
	}
};

void findAndPrintPath(Graph const& graph, int deadline)
{
	vector<lol> mass;
	mass.resize(graph.adjPath.size());
	for (int m = 1; m < graph.adjPath.size(); m++) {
		mass[m].wt = 0;
		mass[m].vertex = 0;
		mass[m].dst = deadline;
		mass[m].ima = graph.adjVert[m][0].name;
	}

	for (int i = 1; i < graph.adjPath.size(); i++)
	{
		for (int k = 0; k < graph.adjPath[i].size(); k++) {
			if (graph.adjVert[i][0].weight + mass[graph.adjVert[i][0].src].wt > mass[graph.adjPath[i][k].dst].wt) {
				mass[graph.adjPath[i][k].dst].wt = graph.adjVert[i][0].weight + mass[graph.adjPath[i][k].src].wt;
			}
		}
	}
	if (deadline < mass[graph.adjPath.size() - 1].wt) {
		cout << "Минимальное время выполнения несопоставимо со сроками:	" << deadline << " < " << mass[graph.adjPath.size() - 1].wt << endl;
	}
	else {
		for (int i = graph.adjPath.size() - 1; 0 < i; i--) {
			for (int k = 0; k < graph.adjPath[i].size(); k++) {
				if (mass[graph.adjPath[i][k].dst].dst - graph.adjVert[graph.adjPath[i][k].dst][0].weight < mass[graph.adjPath[i][k].src].dst) {
					mass[graph.adjPath[i][k].src].dst = mass[graph.adjPath[i][k].dst].dst - graph.adjVert[graph.adjPath[i][k].dst][0].weight;
				}
			}
		}
		for (int k = 1; k < mass.size(); k++) {
			cout << "Вершина (" << k << ")	" << graph.adjVert[k][0].name << "	Начало: " << mass[k].wt << "	Конец:	" << mass[k].dst << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	vector<Edge> edgein;
	ifstream path;
	path.open("graphpath.txt");
	if (!path.is_open()) {
		cout << "Ошибка открытия файла, введите другое название" << endl;
		return 1;
	}
	else
	{
		string line;
		while (getline(path, line)) {
			stringstream ss;
			ss << line;
			string temp;
			int meta, a, b, c;
			while (!ss.eof()) {
				ss >> temp;
				if (stringstream(temp) >> meta)
					a = meta;
				ss >> temp;
				if (stringstream(temp) >> meta)
					b = meta;
				temp = "";
				edgein.push_back({ a,b });
			}
		}
	}
	ifstream vertex;
	vector<Vertex> vert;
	vertex.open("graphvert.txt");
	if (!vertex.is_open()) {
		cout << "Ошибка открытия файла, введите другое название" << endl;
		return 1;
	}
	else
	{
		string line;
		while (getline(vertex, line)) {
			stringstream ss;
			ss << line;
			string temp, c, name;
			int meta, a, b;
			while (!ss.eof()) {
				ss >> temp;
				if (stringstream(temp) >> meta)
					a = meta;
				ss >> temp;
				if (stringstream(temp) >> meta)
					b = meta;
				ss >> temp;
				if (stringstream(temp) >> name)
					c = name;
				temp = "";
				vert.push_back({ a,b,c });
			}
		}
	}
	cout << "Введите номер вершины конца графа: ";
	int count;
	cin >> count;
	Graph grph(edgein, vert, count + 1);
	cout << "Введите срок выполнения: ";
	int deadline;
	cin >> deadline;
	findAndPrintPath(grph, deadline);

	return 0;
}