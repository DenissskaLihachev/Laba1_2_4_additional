#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

#include "Functions.h"

#define VER 2

using namespace std;

//Индивидуальное задание
//	Внесите в готовую программу из предыдущей лабораторной работы следующие изменения :
//
//		1) Программа теперь должна состоять из нескольких файлов.Функция main() должна
//	содержаться в главном файле, в который подключаются остальные файлы.Программу на
//	файлы разделите по функционалу.
//	К примеру :
//		 Файл, содержащий структуру данных(здесь должны быть только структура без
//		экземпляров).
//		 Файл, содержащий функции по работе с файловой системой.
//		 Файл, содержащий функции по работе со списком.
//		Если файлы содержат только функции, то лучше всего создать для них заголовочный файл
//		(.h) с тем же именем, что и файл с описанием / кодом этих функций(.cpp).В заголовочном
//		файле определите прототипы этих функций.В главный файл с функцией main() подгружайте
//		именно заголовочные файлы.
//			2) Добавьте условную компиляцию в программу(#if, #else, #elif и #endif).Определите макрос
//		VER(#define VER).В зависимости от того чему он равен будет компилироваться
//		определенная версия программы :
//
//			1. Данные в структуру считываются только с клавиатуры.Нужно сделать так, чтобы при
//		VER = 1блокировались возможности считывания и сохранения данных в файл.
//			2. Полная версия(VER = 2), позволяющая считывать данные с файла и с клавиатуры.

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int* counter = new int;					//объявляем все нужные нам переменные
	*counter = 1;
	reader* head = NULL;
	head = new reader;
	reader* readers = head;
	reader* tail = NULL;
	tail = new reader;

	while (true)
	{
		if (readers->next == NULL) break;
		readers = readers->next;
		tail = readers;
	}
	readers = head;		//переходим к началу (голове) списка

	std::system("cls");

	fillreaders(head, tail, readers, counter);		//заполняем таблицу, чтобы она не была изначально пустая

	readers = head;		//снова переходим к началу списка

	while (true)
	{
		if (readers->next == NULL) break;
		readers = readers->next;
		tail = readers;
	}
	while (true)
	{
		if (readers->prev == NULL) break;
		readers = readers->prev;
		head = readers;
	}

	while (true)
	{
		std::cout << "*Кол-во читателей*" << *counter << endl;			//наше меню выбора

		std::cout << "1) Добавить  читателя\n";
		std::cout << "2) Сортировать читателей\n";
		std::cout << "3) Изменить данные читателя\n";
		std::cout << "4) Удалить  читателя\n";
		std::cout << "5) Вывести всех читателей\n";
		std::cout << "6) Поиск читателя\n";

#if VER == 2
		std::cout << "7) Сохранить\n";
		std::cout << "8) Загрузить\n\n";
#endif

		std::cout << "Выбор: ";

		int choice; std::cin >> choice;

		std::system("cls");

		readers = head;

		switch (choice)
		{
			case(1):
			{
				try
				{
					addReaders(head, tail, readers, counter);
				}
				catch (const std::exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				break;
			}
			case(2):
			{
				try
				{
					sortReaders(head, tail, readers);
				}
				catch (const std::exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				break;
			}
			case(3):
			{
				try
				{
					transformReaders(head, tail, readers);
				}
				catch (const std::exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				break;
			}
			case(4):
			{
				try
				{
					deleteReaders(head, tail, readers, counter);
				}
				catch (const std::exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				break;
			}
			case(5):
			{
				try
				{
					showReaders(head, tail, readers, counter);
				}
				catch (const std::exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				break;
			}
			case(6):
			{
				try
				{
					searchReaders(head, tail, readers);
				}
				catch (const std::exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				break;
			}

#if VER == 2
			case(7):
			{
				try
				{
					save(head, tail, readers);
				}
				catch (const std::exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				break;
			}
			case(8):
			{
				try
				{
					load(head, tail, readers);
				}
				catch (const std::exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				break;
			}
#endif
		}

		readers = head;

		while (true)
		{
			if (readers->next == NULL) break;
			readers = readers->next;
			tail = readers;
		}
		while (true)
		{
			if (readers->prev == NULL) break;
			readers = readers->prev;
			head = readers;
		}
	}
}