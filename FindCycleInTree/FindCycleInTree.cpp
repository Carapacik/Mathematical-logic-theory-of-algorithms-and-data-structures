#include <iostream>
#include <list>
#include <utility>
#include <map>
#include <string>
#include <fstream>
#include <list>
using namespace std;

struct node {
	std::list<node> children;
	node* parent{};
	string text;
};

class tree {
public:
	void load_from_file(const std::string& file_name);
	node* find_children(node* node_found);
	node* find_first(node* second_node, node* node_root);
	void cycle_finder(node* root_old);
	node& get_root() { return root_; };
private:
	node& add_node(node& parent, const string& item);
	node root_;
};

node& tree::add_node(node& parent, const string& item) {
	parent.children.push_back({ {}, &parent, item });
	return parent.children.back();
}

void tree::load_from_file(const string& file_name) {
	std::ifstream infile(file_name);
	std::string line;
	pair<int, node*> prev = { 0, &get_root() };
	//auto prev_node = parent_node;
	std::string Member;
	std::getline(infile, Member);
	if (Member.find("*") == 0) {
		throw std::runtime_error("Ошибка чтения исходного файла, не найдена вершина!");
	}
	root_ = { {}, nullptr, { {Member}, {} } };
	while (std::getline(infile, line)) {
		auto lvl = 0;
		auto c = '*';
		while (c == '*') {
			c = line.front();
			if (c == '*') {
				line.erase(0, 1);
				lvl++;
			}
		}
		if (lvl < 1) {
			throw std::runtime_error("Ошибка чтения исходного файла, слишком низкий уровень!");
			break;
		}
		if (lvl > prev.first) {
			if ((lvl - prev.first) > 1) {
				throw std::runtime_error("Ошибка чтения исходного файла, уровень ребенка не может различаться от родителя более чем на 1!");
			}
			else {
				auto* new_node = &add_node(*prev.second, line);
				prev.second = new_node;
			}
		}
		else {
			if (lvl == prev.first) {
				auto* new_node = &add_node(*prev.second->parent, line);
				prev.second = new_node;
			}
			else {
				node* addit_node = prev.second->parent;
				for (auto j = 0; j < (prev.first - lvl); j++) {
					addit_node = (addit_node)->parent;
				}
				auto* new_node = &add_node(*addit_node, line);
				prev.second = new_node;
			}
		}
		prev.first = lvl;
	}
}

list<string> listname;
node* tree::find_children(node* node_found) {
	if (node_found == nullptr) {

		return nullptr;
	}
	if (node_found->text == "ROOT") {
		listname.push_back(node_found->text);
	}
	else {
		for (auto& item : listname) {
			if (node_found->text == item) {

				return node_found;
			}
		}
		listname.push_back(node_found->text);
	}
	if (node_found->children.size() != 0) {
		for (auto& item : node_found->children) {
			auto* temp = find_children(&item);
			if (temp != nullptr) {

				return temp;
			}
		}
	}

	return nullptr;
}

list<string> listnamelol;
node* tree::find_first(node* second_node, node* node_root) {
	if (node_root == nullptr) {

		return nullptr;
	}
	if (node_root->text == "ROOT") {
		listnamelol.push_back(node_root->text);
	}
	else {
		for (auto& item : listnamelol) {
			if (node_root->text == second_node->text) {

				return node_root;
			}
		}
		listnamelol.push_back(node_root->text);
	}
	if (node_root->children.size() != 0) {
		for (auto& item : node_root->children) {
			auto* temp = find_first(second_node, &item);
			if (temp != nullptr) {

				return temp;
			}
		}
	}

	return nullptr;
}

void tree::cycle_finder(node* root_old) {
	int lvl1 = 0, lvl2 = 0;
	list<string> cycle1, cycle2;
	//Находим уровни, на которых находятся похожие элементы
	auto* monster1 = find_children(root_old);
	if (monster1 != nullptr) {
		while (monster1->parent != nullptr) {
			monster1 = monster1->parent;
			lvl2++;
		}
		listname.clear();
		listnamelol.clear();
		auto* monster2 = find_first(find_children(root_old), root_old);
		while (monster2->parent != nullptr) {
			monster2 = monster2->parent;
			lvl1++;
		}

		listname.clear();
		auto* root_new = &get_root();
		auto* second_node = find_children(root_new);
		listname.clear();
		listnamelol.clear();
		auto* first_node = find_first(second_node, root_new);

		bool found = false;
		while (found == false) {
			//уровень второго больше первого
			if (lvl1 < lvl2) {
				if (second_node->parent == first_node) {
					cycle2.push_front(second_node->text);
					cycle1.push_back(first_node->text);
					found = true;
				}
				else {
					cycle2.push_front(second_node->text);
					second_node = second_node->parent;
					lvl2--;
				}
			}
			else {
				//уровень первого больше второго
				if (lvl1 > lvl2) {
					if (first_node->parent == second_node) {
						//такого быть не может, но на всякий случай
						cycle1.push_back(first_node->text);
						cycle2.push_front(second_node->text);
						found = true;
					}
					else {
						cycle1.push_back(first_node->text);
						first_node = first_node->parent;
						lvl1--;
					}
				}
				//одинаковые уровни
				else {
					if (first_node->parent == second_node->parent) {
						cycle1.push_back(first_node->text);
						cycle2.push_front(second_node->text);
						first_node = first_node->parent;
						cycle1.push_back(first_node->text);
						found = true;
					}
					else {
						cycle1.push_back(first_node->text);
						cycle2.push_front(second_node->text);
						first_node = first_node->parent;
						second_node = second_node->parent;
					}
				}
			}
		}
		//Вывод цикла если есть
		cout << "Цикл есть: ";
		for (string item : cycle1) {
			cout << item << "-";
		}
		for (string item : cycle2) {
			cout << "-" << item;
		}
		cout << endl;
	}
	else {
		cout << "Циклов не найдено" << endl;
	}
}

int main() {
	tree Family;
	string namefile = "";
	ifstream fin;
	setlocale(LC_ALL, "Russian");
	cout << "Введите название файла: ";

	cin >> namefile;
	fin.open(namefile);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		Family.load_from_file(namefile);
		Family.cycle_finder(&Family.get_root());
	}

	return 0;
}