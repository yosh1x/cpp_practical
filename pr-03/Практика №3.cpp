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
	int cost;
	struct date Date;

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

struct node {
	record data;
	struct node* next;
};

struct node* myHead;
int countItem = 0;

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void addItem(record data)
{
	struct node* newItem = new node();
	newItem->data = data;
	if (countItem == 0) {
		newItem->next = NULL;
	}
	else
	{
		newItem->next = myHead;
	}
	myHead = newItem;
	countItem++;
}

void insertItem(int index, record data) {
	if (not (index >= 0 and index <= countItem and countItem >= 0))
		return;
	if (index == 0) {
		addItem(data);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->data = data;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}

void editItem(int index, record data) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		current->data = data;
	}
	else {
		cout << endl << "Ошибка индекс не в диапазоне";
	}
}
void deleteItem(int index) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		struct node* old;
		if (index == 0) {
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current) {
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				i++;
				current = current->next;
			}
		}
	}

}

void printMyList() {
	struct node* current = myHead;
	cout << endl;
	while (current) {
		cout << " " << current->data.name;
		current = current->next;
	}
}




void DrawWithList() {
	cout << endl;
	cout.width(91); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(90); cout << left << "|Прайс-лист"; cout << "|" << endl;
	cout.width(91); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|Наименование товара ";
	cout << left << "|Тип товара ";
	cout << left << "|Цена за 1 шт (грн) ";
	cout << left << "|Минимальное количество ";
	cout << left << "| Дата       ";
	cout << "|";
	cout << endl;
	cout.width(91); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	struct node* current = myHead;
	while (current) {
		cout << left << "|"; cout.width(20); cout << left << current->data.name;
		cout << left << "|"; cout.width(11); cout << left << current->data.product;
		cout << left << "|"; cout.width(19); cout << left << current->data.count;
		std::cout.precision(2);
		cout << left << "|"; cout.width(23); cout << left << fixed << current->data.cost;
		cout << left << "|";
		printDate(current->data.Date.day, current->data.Date.month, current->data.Date.year, 11);
		cout << "|" << endl;
		current = current->next;
	}
	cout.width(91); cout.fill('-'); cout << "-" << endl;
	cout << "|"; cout.width(89); cout.fill(' '); cout << left << "Примечание: К – канцтовары, О – оргтехника"; cout << "|" << endl;
	cout.width(91); cout.fill('-'); cout << "-" << endl << endl;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct record records[10];
	records[0] = { "Папка","К",4.75000,4,{11,01,2011} };
	records[1] = { "Бумага","К",13.90000,10,{21,10,2012} };
	records[2] = { "Калькулятор","О",411.00000,1,{21,10,2020} };
	addItem(records[0]);
	addItem(records[1]);
	addItem(records[2]);
	DrawWithList();
	struct record newRecord = { "Книга", "К", 123.000, 10, {12,10,2011} };
	insertItem(1, newRecord);
	DrawWithList();
	deleteItem(3);
	DrawWithList();
	struct record editRecord = { "Тетрадь", "О", 123.000, 4, {13,01,2011} };
	editItem(1, editRecord);
	DrawWithList();


}

