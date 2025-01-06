#pragma once

struct Student
{
	char Name[20];
	char Surname[20];
	int Age;
	char Phone[20];
	double GPA; // grade point average
};

struct ArrayStudents
{
	Student **PtrSt;
	int Size;
	int Count;
	int Block;
};

void RussianMessage(const char *str);
void Menu(char ptr[][50], int row);
void InputData(Student *st);
void AddStudents(ArrayStudents &a);
void RemoveStudent(ArrayStudents &a);
void EditStudent(ArrayStudents &a);
void PrintStudents(ArrayStudents &a);
void Destroy(ArrayStudents &a);