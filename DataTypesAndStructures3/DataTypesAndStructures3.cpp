#include<iostream>
#include <map>
#include <fstream>
#include <string>
#include <Windows.h> 
#include <ctime>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count = 0;
	int countall = 0;
	ifstream file;
	string key, word;
	map<string, string> regionscapitals; //Словарь с регионами и их столицами
	file.open("regionscapitals.txt");
	if (!file.is_open())				//Проверка, удалось ли открыть файл
		cout << "Не удалось открыть файл." << endl;
	else {
		while (!file.eof()) {				//Заполнение словаря
			getline(file, key);
			getline(file, word);
			regionscapitals[key] = word;
		}
		file.close();
		cout << "Викторина со столицами!" << endl;
		cout << "Программа дает название региона России, а вы должны назвать его столицу." << endl;
		cout << "Для того, чтобы закончить викторину, введите \"-\" на пустой строке." << endl << endl;
		int random;
		pair<string, string> thepair;
		map<string, string>::iterator it;
		for (unsigned int i = 0; i < regionscapitals.size(); i++) {  //Цикл викторины
			it = regionscapitals.begin(); // Итератор указывает на первую пару из словаря
			random = time(0) % regionscapitals.size(); // Формирование случайного числа (меньшего regionscapitals.size())
			advance(it, random); // Итератор сдвигается на несколько пар
			thepair = *it;
			cout << "Регион: " << thepair.first << endl;
			cout << "Столица: ";
			cin >> word;
			if (word != thepair.second)
				cout << "Неверно!" << endl;
			else
				count++;
			regionscapitals.erase(it); // Удаление пары 
			if (word == "-")
				break;
			countall++;
		}
		cout << "Дано правильных ответов: " << count << endl;
		cout << "Дано неправильных ответов: " << countall - count << endl;
	}
	return 0;
}