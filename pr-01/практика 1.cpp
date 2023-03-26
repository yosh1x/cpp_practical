#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;
struct date
{
	int day;
	int month;
	int year;
};
struct record
{
	const char* name;
	const char* product;
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

void draw(struct record* records,int B)
{

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
	int B = -1;
	int day, month, year;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct record records[10];
	records[0] = { "Папка","К",4.75000,4,{11,01,2011} };
	records[1] = { "Бумага","К",13.90000,10,{21,10,2012} };
	records[2] = { "Калькулятор","О",411.00000,1,{21,10,2020} };
	cout << "введите дату: ";
	cin >> day >> month >> year;
	cout << "выбранная дата:\t" << day << "." << month << "." << year << endl;

	for (int i = 0; i < 3; i++) {
		if ((records[i].Date.day == day) and (records[i].Date.month == month) and (records[i].Date.year == year))B = i; {
		}
	}
	cout << "удаляется строка №" << B + 1 << endl;
	if (B == -1)
	{
		cout << "введена несуществующая дата";
	}




	draw(records,B);
}