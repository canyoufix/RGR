#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

struct Detail {
	string Name;
	int Amount = 0;
	int Weight = 0;
};



void inputArr(const int size, Detail* object);
void outArr(const int size, Detail* object);
void sortStr(const int size, Detail* object);
void saveInFile(const int size, Detail* object, string fileName);
void readFromFile(const int size, Detail* object, string fileName);
void clearFile(string fileName);
bool isFileEmpty(string fileName);


void menu(int *key, const int size, Detail* object, string fileName) 
{
	cout << endl << "�������� ����� ����:" << endl;
	cout << "   1.���� �������" << endl;
	cout << "   2.����� �������" << endl;
	cout << "   3.���������� ������� (�� ����) ������� ��������" << endl;
	cout << "   4.����� ���� ������� � ��������������� ������� �� �����" << endl;
	cout << "   5.���������� ���� ������� � �����" << endl;
	cout << "   6.������ ������� �� �����" << endl;
	cout << "   7.�������� ����" << endl;
	cout << "��� ������ ������� 0" << endl;

	cout << "�����: ";
	cin >> *key;
	cout << endl;

	switch (*key) {
		case 1: 
			inputArr(size, object);
			break;

		case 2: 
			outArr(size, object);
			break;

		case 3: 
			sortStr(size, object);
			break;

		case 4: 
			sortStr(size, object);
			outArr(size, object);
			break;

		case 5: 
			saveInFile(size, object, fileName);
			break;

		case 6: 
			readFromFile(size, object, fileName);
			break;

		case 7:
			clearFile(fileName);
			break;

		case 0:
			exit;
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int key = -1;
	const int size = 3;
	string fileName = "myFile.txt";

	Detail object[size];

	while (key != 0)
		menu(&key, size, object, fileName);
}

void inputArr(const int size, Detail *object) 
{
	cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	cout  << "������� ������:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "\t������������ ������: ";
		cin >> object[i].Name;

		cout << "\t����������: ";
		cin >> object[i].Amount;

		cout << "\t���: ";
		cin >> object[i].Weight;
		cout << endl;
	}

	cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
}

void outArr(const int size, Detail* object) 
{
	cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	cout << "����� �������:" << endl;

	for (int i = 0; i < size; i++) 
	{
		cout << "\t������������ ������:  " << object[i].Name << endl;
		cout << "\t����������: " << object[i].Amount << endl;
		cout << "\t���: " << object[i].Weight << endl;
		cout << endl;
	}

	cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
}

void sortStr(const int size, Detail* object) 
{
	Detail* pObject[3];					//Array of pointer
	for (int i = 0; i < size; i++)
		pObject[i] = (object + i);

	Detail buffer;

	bool isSwap = false;

	for (int i = 0; i < size - 1; i++)
	{
		bool isSwap = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (object[j].Weight < object[j + 1].Weight) {
				buffer = *(pObject[j]);
				*(pObject[j]) = *(pObject[j + 1]);
				*(pObject[j + 1]) = buffer;
				isSwap = true;
			}
		}
		if (isSwap == false)
			break;
	}
	cout << "������ ������������!" << endl;
}

void saveInFile(const int size, Detail* object, string fileName) {
	ofstream fout;

	fout.open(fileName, ofstream::app);				//Open file + ADD

	for (int i = 0; i < size; i++)
		fout.write((char*)&object[i], sizeof(Detail));

	fout.close();
	cout << "\t������ ��������� � ����!" << endl;
}

void readFromFile(const int size, Detail* object, string fileName) {
	if (isFileEmpty(fileName) == false) {
		ifstream fin;
		fin.open(fileName);

		for (int i = 0; i < size; i++)
			fin.read((char*)&object[i], sizeof(Detail));

		fin.close();
		cout << "\t ������ �� ����� ��������!" << endl;
	}
	else {
		cout << "\t���� ����!" << endl;
	}
}

void clearFile(string fileName) {
	fstream file(fileName, ios::out);
	file.close();
	cout << "\t���� ������!" << endl;
}

bool isFileEmpty(string fileName) 
{
	int length;
	ifstream filestr;

	filestr.open(fileName, ios::binary); 
	filestr.seekg(0, ios::end);				//Put cursor of end file
	length = filestr.tellg();				//Find position of cursor
	filestr.close();

	if (length == 0) {
		return true;
	}
	else return false;
}