#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
	cout << '|';cout.width(100); cout.fill('-'); cout << '|' << endl;
	cout << '|';cout.width(58); cout.fill(' ');cout << "Офисные пакеты";cout.width(42);cout.fill(' ');cout << '|' << endl;
	cout << '|';cout.width(100); cout.fill('-'); cout << '|' << endl;
	cout << '|';cout << "Наименование товара";cout.width(5);cout.fill(' ');
	cout << '|'; ;cout << "Тип товара";cout.width(5);cout.fill(' ');
	cout << '|';cout.width(10); cout.fill(' ');cout << "Цена за 1 шт (грн)";
	cout << '|';cout.width(8); cout.fill('-');cout << "Минимальное количество";
	cout << '|';cout.width(11); cout.fill(' ');cout << "Дата";cout.width(8);cout.fill(' ');cout << '|' << endl;
	cout << '|';cout.width(100); cout.fill('-'); cout << '|' << endl;
	
	cout << '|';cout << "Папка";cout.width(19);cout.fill(' ');
	cout << '|';cout << "К";cout.width(14);cout.fill(' ');
	cout << '|';cout << "4.75000";cout.width(12);cout.fill(' ');
	cout << '|';cout << "4";cout.width(22);cout.fill(' ');
	cout << '|';cout << "03.07.2022";cout.width(9);cout.fill(' ');cout << '|' << endl;

	cout << '|';cout.width(100); cout.fill('-'); cout << '|' << endl;

	cout << '|';cout << "Бумага";cout.width(18);cout.fill(' ');
	cout << '|';cout << "К";cout.width(14);cout.fill(' ');
	cout << '|';cout << "13.90000";cout.width(11);cout.fill(' ');
	cout << '|';cout << "10";cout.width(21);cout.fill(' ');
	cout << '|';cout << "03.04.2021";cout.width(9);cout.fill(' ');cout << '|' << endl;

	cout << '|';cout.width(100); cout.fill('-'); cout << '|' << endl;

	cout << '|';cout << "Калькулятор";cout.width(13);cout.fill(' ');
	cout << '|';cout << "О";cout.width(14);cout.fill(' ');
	cout << '|';cout << "411.00000";cout.width(10);cout.fill(' ');
	cout << '|';cout << "1";cout.width(22);cout.fill(' ');
	cout << '|';cout << "04.03.2022";cout.width(9);cout.fill(' ');cout << '|' << endl;

	cout << '|';cout.width(100); cout.fill('-'); cout << '|' << endl;
	cout << '|';cout << ("Примечание: К – канцтовары, О – оргтехника");cout.width(58);cout.fill(' ');cout << '|' << endl;
	cout << '|';cout.width(100); cout.fill('-'); cout << '|' << endl;



	



	

}
