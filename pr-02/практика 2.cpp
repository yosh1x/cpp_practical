#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>


using namespace std;
struct date
{
	int day;
	int month;
	int year;
};
struct record
{
	char name[20];
	char product[20];
	double count;
	double cost;
	date Date;
};

void drawdate(int day, int month, int year, int wline)
{
	int w = 10;
	int delta = (wline - w);
	cout.width(delta); cout << " ";
	cout << left;
	if (day > 9) cout << day;
	else cout << "0" << day;
	cout << ".";
	if (month > 9) cout << month;
	else cout << "0" << month;
	cout << ".";
	cout << year << "|" << endl;
}

void draw(struct record* records, int B)
{
	cout << endl << endl << endl;
	cout.width(90); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(89); cout << left << "|Прайс-лист"; cout << "|" << endl;
	cout.width(90); cout.fill('-'); cout << "-" << endl;
	cout << left << "|Наименование товара ";
	cout << left << "|Тип товара ";
	cout << left << "|Цена за 1 шт (грн) ";
	cout << left << "|Минимальное количество ";
	cout << left << "| Дата ";
	cout << "     |" << endl;
	cout.width(90); cout.fill('-'); cout << "-" << endl;
	for (int i = 0; i < 3; i++)
	{
		if (i != B) {
			cout.fill(' ');
			cout << left << "|"; cout.width(20); cout << left << records[i].name;
			cout << left << "|"; cout.width(11); cout << left << records[i].product;
			cout << left << "|"; cout.width(19); cout << left << records[i].count;
			std::cout.precision(2);
			cout << left << "|"; cout.width(23); cout << left << fixed << records[i].cost;
			cout << left << "|";
			drawdate(records[i].Date.day, records[i].Date.month, records[i].Date.year, 11);
		}

	}
	cout.width(90); cout.fill('-'); cout << "-" << endl;
	cout << "|"; cout.width(88); cout.fill(' '); cout << left << "Примечание: К – канцтовары, О – оргтехника"; cout << "|" << endl;
	cout.width(90); cout.fill('-'); cout << "-" << endl << endl;
}


int main()
{

	int c = 0;
	int day, month, year;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct record records[10];
	records[0] = { "Папка","К",4.75000,4,{11,01,2011} };
	records[1] = { "Бумага","К",13.90000,10,{21,10,2012} };
	records[2] = { "Калькулятор","О",411.00000,1,{21,10,2020} };
	cout << "Практическая работа №0" << endl << endl << endl;
	draw(records, 0);
	cout << endl << endl << endl;
	cout << "Практическая работа №1\n";
	cout << "введите дату: ";
	cin >> day >> month >> year;
	cout << "выбранная дата:\t" << day << "." << month << "." << year << endl;

	for (int i = 0; i < 3; i++) {
		if ((records[i].Date.day == day) and (records[i].Date.month == month) and (records[i].Date.year == year))c = i; {
		}
	}
	cout << "удаляется строка №" << c + 1 << endl;
	if (c == -1)
	{
		cout << "введена несуществующая дата";
	}
	draw(records, c);
	cout << endl << endl << endl;





	cout << "Практическая работа №2\n";
	cout << endl << endl << endl;
	record* A;
	int n = 3;
	A = (record*)malloc(n * sizeof(record));
	for (int i = 0; i < 3; i++)
	{
		A[i] = records[i];
	}


	record** B;
	B = (record**) new record * [10];
	for (int i = 0; i < 10; i++) {
		B[i] = (record*) new record;
		*(B[i]) = records[i];
	}
	A = (record*)realloc(A, 10 * sizeof(record));


	for (int i = 0; i < 10; i++) {
		cout << endl << "адрес A[i] " << &A[i] << " A[i]->name " << A[i].name;

	}
	for (int i = 0; i < 10; i++) {

		cout << endl << "адрес B[i] " << &B[i] << " B[i]->name " << (*B[i]).name;
	}

	for (int i = 0; i < 10; i++) {
		delete B[i];
	}
	delete[]B;
	free(A);
}
