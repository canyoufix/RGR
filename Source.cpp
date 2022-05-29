#include <iostream>
#include <string>
#include <fstream>

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



void menu(int key, const int size, Detail* object, string fileName) 
{
	cout << endl << "�������� ����� ����:" << endl;
	cout << "   1.���� ������ � ������������ �������" << endl;
	cout << "   2.����� ������ � �������� �������" << endl;
	cout << "   3.���������� ������� �� ��������� ���� � ������� ��������" << endl;
	cout << "   4.����� ���� ������� � ��������������� ������� �� �����" << endl;
	cout << "   5.���������� ���� ������� � �����" << endl;
	cout << "   6.������ ������� �� �����" << endl;
	cout << "   ��� ������ ������� 0" << endl;

	cout << "�����: ";
	cin >> key;
	cout << endl;

	switch (key) {
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

		case 0:
			exit;
	}
}

void main() {
	int key = 0;
	setlocale(LC_ALL, "ru");
	const int size = 3;
	string fileName = "myFile.txt";

	Detail object[size];
	
	while (true) {
		menu(key, size, object, fileName);
	}
	
}

void inputArr(const int size, Detail *object) {
	cout << "___\t" << "___\t" << "___\t" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << endl << "������������ ������: ";
		cin >> object[i].Name;

		cout << "����������: ";
		cin >> object[i].Amount;

		cout << "���: ";
		cin >> object[i].Weight;
	}
	cout << "___\t" << "___\t" << "___\t" << endl;
	cout << "������ �������!" << endl;
}

void outArr(const int size, Detail* object) {
	setlocale(LC_ALL, "ru");
	cout << endl << endl << '\t';
	cout << "... ... ����� �������: ... ..." << endl;
	for (int i = 0; i < size; i++) 
	{
		cout << "������������ ������:  " << object[i].Name << endl;
		cout << "����������: " << object[i].Amount << endl;
		cout << "���: " << object[i].Weight << endl;
		cout << endl;
	}
	cout << "������ ��������!" << endl;
}

void sortStr(const int size, Detail* object) {

	Detail* pObject[3];
	for (int i = 0; i < size; i++) {
		pObject[i] = (object + i);
	}

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
	
	fout.open(fileName, ofstream::app);

	for (int i = 0; i < size; i++) {
		fout.write((char*)object, sizeof(Detail));
	}

	fout.close();
	cout << "������ ��������� � �����!" << endl;
}

void readFromFile(const int size, Detail* object, string fileName) {
	ifstream fin;
	int i = 0;

	while (fin.read((char*)&object[i], sizeof(Detail)))	i++;

	fin.close();
	cout << "������ �� ����� ��������!" << endl;
}