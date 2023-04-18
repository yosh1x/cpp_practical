#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>


using namespace std;
struct date
{
	int day;
	int month;
	int year;
};
struct record
{
	unsigned char name[20];
	char product[20];
	float count;
	int cost;
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
	for (int i = 0; i < 4; i++)
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

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct record records[4];
	records[0] = { "Папка","К",4.75,4,{11,01,2011} };
	records[1] = { "Бумага","К",13.90, 10,{21,10,2012} };
	records[2] = { "Калькулятор","О",411.00000,1,{21,10,2020} };


	FILE* textFile;
	fopen_s(&textFile, "textFile.txt", "w");
	for (int i = 0; i < 3; i++) {
		fprintf(textFile, "%s %s %f %d %d %d %d \n", \
			records[i].name, \
			records[i].product, \
			records[i].count, \
			records[i].cost, \
			records[i].Date.day, records[i].Date.month, records[i].Date.year);
	}
	fclose(textFile);


	fopen_s(&textFile, "textFile.txt", "r");
	record readRecords[3];
	for (int i = 0; i < 3; i++) {
		fscanf_s(textFile, "%s", readRecords[i].name, _countof(readRecords[i].name));
		fscanf_s(textFile, "%s", readRecords[i].product, _countof(readRecords[i].product));
		fscanf_s(textFile, "%f", &readRecords[i].count);
		fscanf_s(textFile, "%d", &readRecords[i].cost);
		fscanf_s(textFile, "%d", &readRecords[i].Date.day);
		fscanf_s(textFile, "%d", &readRecords[i].Date.month);
		fscanf_s(textFile, "%d", &readRecords[i].Date.year);
	}
	fclose(textFile);
	draw(readRecords, 3);




	record inRecord = { "Перец", "К", 4.22,3, {07,9,2004} }; ;

	fopen_s(&textFile, "textFile.txt", "a");
	fprintf(textFile, "%s %s %f %d %d %d %d \n", \
		inRecord.name, \
		inRecord.product, \
		inRecord.count, \
		inRecord.cost, \
		inRecord.Date.day, inRecord.Date.month, inRecord.Date.year);
	fclose(textFile);


	record fileRecords[4];
	fopen_s(&textFile, "./textFile.txt", "r");
	for (int i = 0; i < 4; i++) {
		fscanf_s(textFile, "%s", fileRecords[i].name, _countof(fileRecords[i].name));
		fscanf_s(textFile, "%s", fileRecords[i].product, _countof(fileRecords[i].product));
		fscanf_s(textFile, "%f", &fileRecords[i].count);
		fscanf_s(textFile, "%d", &fileRecords[i].cost);
		fscanf_s(textFile, "%d", &fileRecords[i].Date.day);
		fscanf_s(textFile, "%d", &fileRecords[i].Date.month);
		fscanf_s(textFile, "%d", &fileRecords[i].Date.year);
	}
	fclose(textFile);
	draw(fileRecords, 4);

}