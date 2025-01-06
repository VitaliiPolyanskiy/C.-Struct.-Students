#include <windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "Student.h"
using namespace std;


void RussianMessage(const char *str)
{
	char *buf = new char[strlen(str) + 1];
	CharToOemA(str, buf);
	cout << buf;
	delete[]buf;
}

void Menu(char ptr[][50], int row)
{
	for (int i = 0; i < row; i++)
	{
		RussianMessage(ptr[i]);
		cout << endl;
	}
}

void InputData(Student *st)
{
	RussianMessage("Введите имя студента: ");
	cin >> st->Name;
	RussianMessage("Введите фамилию студента: ");
	cin >> st->Surname;
	RussianMessage("Введите возраст студента: ");
	cin >> st->Age;
	RussianMessage("Введите телефон студента: ");
	cin >> st->Phone;
	RussianMessage("Введите средний балл студента: ");
	cin >> st->GPA;
}

void AddStudents(ArrayStudents &a)
{
	system("cls");
	int number;
	RussianMessage("Сколько студентов добавить? ");
	cin >> number;
	if (number <= 0)
		return;
	int new_num = a.Count + number;
	if (a.Size < new_num)
	{
		a.Size = new_num + a.Block - new_num % a.Block;
		Student **temp = new Student *[a.Size];
		for (int i = 0; i < a.Count; i++)
			temp[i] = a.PtrSt[i];
		delete[]a.PtrSt;
		a.PtrSt = temp;
	}
	for (int i = 0; i < number; i++)
	{
		Student *st = new Student;
		RussianMessage("Введите данные ");
		cout << i + 1;
		RussianMessage(" студента\n");
		InputData(st);
		a.PtrSt[a.Count++] = st;
	}
	RussianMessage("В список добавлены новые студенты!");
	_getch();
}

void RemoveStudent(ArrayStudents &a)
{
	system("cls");
	char Name[20], Surname[20];
	RussianMessage("Введите имя студента: ");
	cin >> Name;
	RussianMessage("Введите фамилию студента: ");
	cin >> Surname;
	for (int i = 0; i < a.Count; i++)
	{
		if (!strcmp(Name, a.PtrSt[i]->Name) && !strcmp(Surname, a.PtrSt[i]->Surname))
		{
			delete a.PtrSt[i];
			for (int j = i; j < a.Count - 1; j++)
				a.PtrSt[j] = a.PtrSt[j + 1];
			a.PtrSt[--a.Count] = nullptr;
			RussianMessage("Данные студента удалены!");
			_getch();
			return;
		}
	}
	RussianMessage("Студент не найден!");
	_getch();
}

void EditStudent(ArrayStudents &a)
{
	system("cls");
	char Name[20], Surname[20];
	RussianMessage("Введите имя студента: ");
	cin >> Name;
	RussianMessage("Введите фамилию студента: ");
	cin >> Surname;
	for (int i = 0; i < a.Count; i++)
	{
		if (!strcmp(Name, a.PtrSt[i]->Name) && !strcmp(Surname, a.PtrSt[i]->Surname))
		{
			RussianMessage("Введите новые данные!\n");
			InputData(a.PtrSt[i]);
			RussianMessage("Данные студента изменены!");
			_getch();
			return;
		}
	}
	RussianMessage("Студент не найден!");
	_getch();
}

void PrintStudents(ArrayStudents &a)
{
	system("cls");
	cout << setw(15);
	RussianMessage("Имя");
	cout << setw(15);
	RussianMessage("Фамилия");
	cout << setw(10);
	RussianMessage("Возраст");
	cout << setw(20);
	RussianMessage("Телефон");
	cout << setw(15);
	RussianMessage("Средний балл");
	cout << endl << endl;
	for (int i = 0; i < a.Count; i++)
	{
		cout << setw(15) << (*a.PtrSt[i]).Name
			<< setw(15) << (*a.PtrSt[i]).Surname
			<< setw(10) << (*a.PtrSt[i]).Age
			<< setw(20) << (*a.PtrSt[i]).Phone
			<< setw(15) << (*a.PtrSt[i]).GPA
			<< endl;
	}
	_getch();
}

void Destroy(ArrayStudents &a)
{
	for (int i = 0; i < a.Count; i++)
		delete a.PtrSt[i];
	delete[] a.PtrSt;
	memset(&a, 0, sizeof(ArrayStudents));
}


