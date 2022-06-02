#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

struct Detail {
	char Name[25];
	int Amount = -1;
	float Weight = 0.0;
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
int numOfArrElem(Detail* object);
bool isCheckEror();



void menu(int *key, Detail* object, string fileName) 
{
	cout << endl << "Выберите пункт меню:" << endl;
	cout << "   1.Ввод записей" << endl;
	cout << "   2.Вывод записей" << endl;
	cout << "   3.Ввод записи в определенный номер" << endl;
	cout << "   4.Вывод записи с определенным номером" << endl;
	cout << "   5.Сортировка записей (по весу) в порядке убывания" << endl;
	cout << "   6.Вывод всех записей в отсортированном порядке на экран" << endl;
	cout << "   7.Сохранение всех записей в файле" << endl;
	cout << "   8.Чтение записей из файла" << endl;
	cout << "   9.Очистить файл" << endl;
	cout << "Для выхода введите 0" << endl;

	cout << "Пункт: ";
	cin >> *key;
	cout << endl;

	if (isCheckEror() == false) {
		switch (*key) {
		case 1:
			inputArr(object);
			break;

		case 2:
			outArr(object);
			break;

		case 3:
			cout << "Какую деталь вы хотите заменить?: ";
			int number1;
			cin >> number1;
			inputArr(object, number1);
			break;

		case 4:
			cout << "Деталь под каким номером вы хотите вывести?: ";
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
			cout << "\tФАЙЛ ОЧИЩЕН!" << endl;
			break;

		case 0:
			break;

		default:
			cout << "Выбранного пукнта нет в меню!" << endl;
			menu(key, object, fileName);
		}
	}
	else {
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
		menu(&key, object, fileName);
}

void inputArr(Detail *object) 
{
	int i = 0, number;

	int endIndex = numOfArrElem(object);

	cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	cout << "Сколько записей вы хотите ввести?: ";

	cin >> number;

	if (number <= 0) {
		cout << "\t Неверное значение!" << endl;
	}
	else {
		cout << endl << "Введите детали:" << endl;

		for (endIndex, i = 0; i < number; endIndex++, i++)
		{
			cout << "[ID " << endIndex + 1 << "]";
			cout << "\tНаименование детали: ";
			cin.ignore();
			cin.getline(object[endIndex].Name, 25);

			cout << "\tКоличество: ";
			cin >> object[endIndex].Amount;
			while (isCheckEror() != false || object[endIndex].Amount < 0) {
				cout << "\t\tНовое значение: ";
				cin >> object[endIndex].Amount;
			}

			cout << "\tВес: ";
			cin >> object[endIndex].Weight;
			while (isCheckEror() != false || object[endIndex].Weight <= 0) {
				cout << "\t\tНовое значение: ";
				cin >> object[endIndex].Weight;
			}

			cout << endl;
		}

		cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	}
}
void inputArr(Detail* object, int number)
{
	if (number <= sizeArr && number > 0) {
		cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
		cout << "[ID " << number << "]";
		cout << "Введите деталь:" << endl;

		
		cout << "\tНаименование детали: ";
		cin.ignore();
		cin.getline(object[number - 1].Name, 25);

		cout << "\tКоличество: ";
		cin >> object[number - 1].Amount;
		while (isCheckEror() != false || object[number - 1].Amount < 0) {
			cout << "\t\tНовое значение: ";
			cin >> object[number - 1].Amount;
		}

		cout << "\tВес: ";
		cin >> object[number - 1].Weight;
		while (isCheckEror() != false || object[number - 1].Weight <= 0) {
			cout << "\t\tНовое значение: ";
			cin >> object[number - 1].Weight;
		}

		cout << endl;

		cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	}
	else {
		cout << "Записи с таким номером не существует!" << endl;
		return;
	}

	if (object[number - 2].Name == "") {
		int endIndex = 0;
		endIndex = numOfArrElem(object);

		Detail buffer;
		buffer = object[endIndex];
		object[endIndex] = object[number - 1];
		object[number - 1] = buffer;
	}
}

void outArr(Detail* object)
{
	int i = 0;

	if (object[i].Amount == -1) {
		cout << "\tСписок пуст!" << endl;
	}
	else 
	{
		cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
		cout << "Вывод деталей:" << endl;

		while (object[i].Amount != -1)
		{
			cout << "[ID " << i + 1 << "]";
			cout << "\tНаименование детали:  " << object[i].Name << endl;
			cout << "\tКоличество: " << object[i].Amount << endl;
			cout << "\tВес: " << object[i].Weight << endl;
			cout << endl;

			i++;
		}
		cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	}
}
void outArr(Detail* object, int number) 
{
	if (number <= sizeArr && number > 0 && object[number - 1].Name != "")
	{
		cout << endl << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
		cout << "Вывод детали:" << endl;

		cout << "[ID " << number << "]";
		cout << "\tНаименование детали:  " << object[number - 1].Name << endl;
		cout << "\tКоличество: " << object[number - 1].Amount << endl;
		cout << "\tВес: " << object[number - 1].Weight << endl;
		cout << endl;

		cout << "\t... ... ... ... ... ... ... ... ... ... ..." << endl;
	}
	else {
		cout << "Запись пуста, либо записи не существует!" << endl;
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
	cout << "Массив отсортирован!" << endl;
}

void saveInFile(Detail* object, string fileName) {
	clearFile(fileName);
	ofstream fout;

	fout.open(fileName);				//Open file + NoAdd

	int endIndex;
	endIndex = numOfArrElem(object);

	for (int i = 0; i < endIndex; i++)
		fout.write((char*)&object[i], sizeof(Detail));

	fout.close();
	cout << "\tДАННЫЕ СОХРАНЕНЫ В ФАЙЛ!" << endl;
}

void readFromFile(Detail* object, string fileName) {
	if (isFileEmpty(fileName) == false) {
		ifstream fin;
		fin.open(fileName);

		int i = 0;
		while (fin.read((char*)&object[i], sizeof(Detail))) {
			i++;
		}

		fin.close();
		cout << "\t ДАННЫЕ ИЗ ФАЙЛА ПОЛУЧЕНЫ!" << endl;
	}
	else {
		cout << "\tФАЙЛ ПУСТ, ЛИБО ФАЙЛА НЕ СУЩЕСТВУЕТ!" << endl;
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

int numOfArrElem(Detail* object) {
	int numOfElem = 0;
	while (object[numOfElem].Amount != -1)
		numOfElem++;

	return numOfElem;
}

bool isCheckEror() 
{
	if (cin.fail() == 0) {
		return false;
	}
	else {
		while (cin.fail()) 
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\t\tВведенно неверное значение, повторите ввод.";
		}
		return true;
	}
}