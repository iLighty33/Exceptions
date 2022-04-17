// Персональный шаблон проекта C++
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double division(double num1, double num2) {
	if (num2 == 0)
		throw invalid_argument("обнаружено деление на ноль");
	return num1 / num2;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	/*
	try { // Блок, в который необходимо поместить часть программы, в которой может возникнуть исключительная ситуация.
		cout << "Введите число от 1 до 10: ";
		int x;
		cin >> x;
		// если введённое число нижу указанного диапазона, то "бросается" исключение со значением 0
		if (x < 1)
			throw 0;
		// если введённое число выше указанного диапазона, то "бросается" исключение со строковым значением
		if (x > 10)
			throw "Введённое число больше указанного диапазона";
		// команда throw останавливаем дальнейшее выполнение блока try
		cout << "Введено правильное число\n";
	}
	catch (const int ex) { // блок catch, который "ловит" исключения со значением int и выполняется, если такое исключение было "брошено"
		if (ex == 0)
			cout << "Ошибка!\nВведённое число меньше указанного диапазона\n";
		if (ex == 11)
			cout << "Ошибка!\nВведённое число больше указанного диапазона\n";
	}
	catch (const char ex[]) { // блок catch, который "ловит" исключения со строковым значением и выполняется, если такое исключение было "брошено"
		cout << "Ошибка!\n" << ex << endl;
	}
	*/
	
	/*bool fer = true;
	do {
		try {
			string nStr;
			cout << "Введите число: ";
			getline(cin, nStr);
			int num = stoi(nStr); // throw - спрятан в функции stoi
			cout << "Введено: " << num << endl;
			fer = false;
		}
		catch (const exception& ex) { // ex - объект класса exception, в котором описывается суть ошибки.
			string err = ex.what();
			if (err == "invalid stoi argument")
				cout << "Ошибка: " << err << endl;
		}
	} while (fer);
	*/

	/*try {
		cout << "Введите два числа: ";
		cin >> n >> m;
		cout << n << " / " << m << "=" << division(n, m) << endl;
	}
	catch (const invalid_argument &ex) {
		cout << "Ошибка: " << ex.what() << endl; // возвращает то, что мы передали в кавычках, когда бросали исключение.
	}*/

	string path = "file.tx";
	ifstream in;
	in.exceptions(ios::badbit | ios::eofbit | ios::failbit); // набор исключений, которые мы включаем.
	try {
		cout << "Попытка открытия файла...\n";
		in.open(path);
		cout << "Файл открыт для чтения.\n";
		cout << "Содержимое файла:\n";
		string str;
		getline(in, str);
		cout << str << endl;
		in.close();
	}
	catch (const ifstream::failure &ex) {
		cout << "Ошибка: " << ex.what() << endl;
		cout << "Код ошибки: " << ex.code() << endl;
	}
	

	return 0;
}