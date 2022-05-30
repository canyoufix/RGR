#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

struct Detail {
	string Name = "";
	int Amount = 0;
	int Weight = 0;
};

const int sizeArr = 10;

void inputArr(Detail* object);
void inputArr(Detail* object, int number);
void outArr(Detail* object);
void outArr(Detail* object, int number);
void sortStr(Detail* object);
void saveInFile(Detail* object, string fileName);
void readFromFile(Detail* object, string fileName);
void clearFile(string fileName);
bool isFileEmpty(string fileName);



void menu(int *key, Detail* object, string fileName) 
{
	cout << endl << "�������� ����� ����:" << endl;
	cout << "   1.���� �������" << endl;
	cout << "   2.����� �������" << endl;
	cout << "   3.���� ������ � ������������ �����" << endl;
	cout << "   4.����� ������ � ������������ �������" << endl;
	cout << "   5.���������� ������� (�� ����) � ������� ��������" << endl;
	cout << "   6.����� ���� ������� � ��������������� ������� �� �����" << endl;
	cout << "   7.���������� ���� ������� � �����" << endl;
	cout << "   8.������ ������� �� �����" << endl;
	cout << "   9.�������� ����" << endl;
	cout << "��� ������ ������� 0" << endl;

	cout << "�����: ";
	cin >> *key;
	cout << endl;

	switch (*key) {
		case 1: 
			inputArr(object);
			break;

		case 2: 
			outArr(object);
			break;

		case 3:
			cout << "����� ������ �� ������ ��������?: ";
			int number1;
			cin >> number1;
			inputArr(object, number1);
			break;

		case 4:
			cout << "������ ��� ����� ������� �� ������ �������?: ";
			int number;
			cin >> number;
			outArr(object, number);
			break;

		case 5: 
			sortStr(object);
			break;

		case 6: 
			sortStr(object);
			outArr(object);
			break;

		case 7: 
			saveInFile(object, fileName);
			break;

		case 8: 
			readFromFile(object, fileName);
			break;

		case 9:
			clearFile(fileName);
			cout << "\t���� ������!" << endl;
			break;

		case 0:
			break;

		default:
			cout << "���������� ������ ��� � ����!" << endl;
			menu(key, object, fileName);
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int key = -1;
	string fileName = "myFile.txt";

	Detail object[sizeArr];

	while (key != 0)
		menu(&key,object, fileName);
}

void inputArr(Detail *object) 
{
	int i = 0, endOfArr = 0, number;

	while (object[endOfArr].Name != "")
		endOfArr++;
		

	cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	cout << "������� ������� �� ������ ������?: ";

	cin >> number;
	cout  << "������� ������:" << endl;
	
	for (endOfArr, i = 0; i < number; endOfArr++, i++)
	{
		cout << "[ID " << i + 1 << "]";
		cout << "\t������������ ������: ";
		cin >> object[endOfArr].Name;

		cout << "\t����������: ";
		cin >> object[endOfArr].Amount;

		cout << "\t���: ";
		cin >> object[endOfArr].Weight;
		cout << endl;
	}
		
	cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
}
void inputArr(Detail* object, int number)
{
	if (number <= sizeArr && number > 0) {
		cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
		cout << "[ID " << number << "]";
		cout << "������� ������:" << endl;

		
		cout << "\t������������ ������: ";
		cin >> object[number - 1].Name;

		cout << "\t����������: ";
		cin >> object[number - 1].Amount;

		cout << "\t���: ";
		cin >> object[number - 1].Weight;
		cout << endl;

		cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	}
	else {
		cout << "������ � ����� ������� �� ����������!" << endl;
		return;
	}

	if (object[number - 2].Name == "") {
		int endOfArr = 0;
		while (object[endOfArr].Name != "")
			endOfArr++;

		Detail buffer;
		buffer = object[endOfArr];
		object[endOfArr] = object[number - 1];
		object[number - 1] = buffer;
	}
}

void outArr(Detail* object)
{
	int i = 0;
	cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	cout << "����� �������:" << endl;

	while (object[i].Name != "") {
		cout << "[ID " << i + 1 << "]";
		cout << "\t������������ ������:  " << object[i].Name << endl;
		cout << "\t����������: " << object[i].Amount << endl;
		cout << "\t���: " << object[i].Weight << endl;
		cout << endl;

		i++;
	}

	cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
}
void outArr(Detail* object, int number) 
{
	if (number <= sizeArr && number > 0 && object[number - 1].Name != "")
	{
		cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
		cout << "����� ������:" << endl;

		cout << "[ID " << number << "]";
		cout << "\t������������ ������:  " << object[number - 1].Name << endl;
		cout << "\t����������: " << object[number - 1].Amount << endl;
		cout << "\t���: " << object[number - 1].Weight << endl;
		cout << endl;

		cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	}
	else {
		cout << "������ �����, ���� ������ �� ����������!" << endl;
	}
}

void sortStr(Detail* object) 
{
	Detail* pObject[sizeArr];					//Array of pointer
	for (int i = 0; i < sizeArr; i++)
		pObject[i] = (object + i);

	Detail buffer;

	bool isSwap = false;

	for (int i = 0; i < sizeArr - 1; i++)
	{
		bool isSwap = false;
		for (int j = 0; j < sizeArr - 1 - i; j++)
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

void saveInFile(Detail* object, string fileName) { //��������
	clearFile(fileName);
	ofstream fout;

	fout.open(fileName, ofstream::app);				//Open file + ADD

	for (int i = 0; i < sizeArr; i++)
		fout.write((char*)&object[i], sizeof(Detail));

	fout.close();
	cout << "\t������ ��������� � ����!" << endl;
}

void readFromFile(Detail* object, string fileName) {
	if (isFileEmpty(fileName) == false) {
		ifstream fin;
		fin.open(fileName);

		for (int i = 0; i < sizeArr; i++)
			fin.read((char*)&object[i], sizeof(Detail));

		fin.close();
		cout << "\t ������ �� ����� ��������!" << endl;
	}
	else {
		cout << "\t���� ����, ���� ����� �� ����������!" << endl;
	}
}

void clearFile(string fileName) {
	fstream file(fileName, ios::out);
	file.close();
}

bool isFileEmpty(string fileName) 
{
	int length;
	ifstream filestr;

	filestr.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		filestr.open(fileName, ios::binary);
		filestr.seekg(0, ios::end);				//Put cursor of end file
		length = filestr.tellg();				//Find position of cursor
		filestr.close();

		if (length == 0) {
			return true;
		}
		else return false;
	}
	catch (const std::exception&)
	{
		return true;
	}
}