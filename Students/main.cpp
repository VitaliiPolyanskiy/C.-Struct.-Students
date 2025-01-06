#include <Windows.h>
#include <conio.h>
#include "Student.h"

int main()
{
	ArrayStudents a;
	memset(&a, 0, sizeof(ArrayStudents));
	a.Block = 10;
	char menu[][50] = {
		"1. Добавление студентов",
		"2. Удаление студента",
		"3. Модификация студента",
		"4. Вывод на экран списка",
		"5. Выход" };
	while (true)
	{
		system("cls");
		Menu(menu, 5);
		int choice = _getch();
		switch (choice)
		{
		case '1':
			AddStudents(a);
			break;
		case '2':
			RemoveStudent(a);
			break;
		case '3':
			EditStudent(a);
			break;
		case '4':
			PrintStudents(a);
			break;
		case '5':
			Destroy(a);
			return 0;
		}
	}

	return 0;
}