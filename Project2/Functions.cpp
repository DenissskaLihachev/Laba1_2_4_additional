#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

#include "Functions.h"
#include "Struct.h"

using namespace std;

void save(reader* readers, reader* tail, reader* head)
{
	if (tail == NULL && head == NULL)
		throw exception("\nНет данных для сохранения...");

	string defaultFile = ("SaveReaders.txt");
	string individualFile;

	cout << "1) Сохранить в файле по умолчанию (SaveReaders.txt)\t2) Сохранить в своем файле\n\nВыбор: "; int choice; cin >> choice;

	std::system("cls");

	switch (choice)
	{
	case(1):
	{
		ofstream saveReaders("SaveReaders.txt");

		readers = head;

		while (true)
		{
			saveReaders << "ФИО: " << readers->data.surname << " " << readers->data.name << " " << readers->data.patronymic << " Номер билета: " << readers->data.numberTicket << " Название книги: " << readers->data.booksName << " День возврата: " << readers->data.refundPeriod << " Max. возврат: " << readers->data.MaxRefundPeriod << endl;

			if (readers == tail)
				break;
			readers = readers->next;
		}
		cout << "Операция завершена!";

		saveReaders.close();

		_getch();
		std::system("cls");
		break;
	}
	case(2):
	{
		cout << "Введите название файла (с раширевнием '.txt'): "; cin >> individualFile;

		std::system("cls");

		ofstream saveReaders(individualFile);

		readers = head;

		while (true)
		{
			saveReaders << "ФИО: " << readers->data.surname << " " << readers->data.name << " " << readers->data.patronymic << " Адресс: " << readers->data.numberTicket << " Номер тел.: " << readers->data.booksName << " День оплаты: " << readers->data.refundPeriod << " Сумма: " << readers->data.MaxRefundPeriod << endl;

			if (readers == tail)
				break;
			readers = readers->next;
		}
		cout << "Операция завершена!";

		saveReaders.close();

		_getch();
		std::system("cls");
		break;
	}
	}
}
//сохранение
void load(reader* readers, reader* tail, reader* head)
{
	string defaultFile = ("SaveReaders.txt");
	string individualFile;
	std::cout << "1) Загрузить из файла по умолчанию\t2) Загрузить из своего файла\n\nВыбор: ";
	int inNum;
	cin >> inNum;
	std::system("cls");
	switch (inNum)
	{
	case(1):
	{
		ifstream inputReaders("SaveReaders.txt");

		if (inputReaders.bad())
			throw exception("\n\tОшибка ввода-вывода при чтении");

		if (inputReaders.eof())
			throw exception("\n\tДостигнут конец файла");

		if (inputReaders.fail())
			throw exception("\n\tНеверный формат данных");


		int size = 0;
		inputReaders >> size;

		for (int i = 0; i < size; i++)
		{
			if (readers == NULL) {
				readers = new reader;
				head = readers;
				tail = readers;
			}
			else
			{
				readers = tail;
				readers->next = new reader;
				readers->next->prev = readers;
				readers = readers->next;
				tail = readers;
			}

			inputReaders.get();
			getline(inputReaders, readers->data.surname);
			getline(inputReaders, readers->data.name);
			getline(inputReaders, readers->data.patronymic);
			getline(inputReaders, readers->data.numberTicket);
			getline(inputReaders, readers->data.booksName);
			getline(inputReaders, readers->data.refundPeriod);
			inputReaders >> readers->data.MaxRefundPeriod;
		}

		std::cout << "Операция завершена!";

		_getch();
		std::system("cls");
		break;
	}
	case(2):
	{
		std::cout << "Введите название файла (с расширением '.txt'): "; cin >> individualFile;

		std::system("cls");

		ifstream inReaders(individualFile);

		if (inReaders.bad())
			throw exception("\n\tОшибка ввода-вывода при чтении");


		if (inReaders.eof())
			throw exception("\n\tДостигнут конец файла");


		if (inReaders.fail())
			throw exception("\n\tНеверный формат данных");

		int size = 0;
		inReaders >> size;

		readers = new reader;
		head = readers;

		for (int i = 0; i < size; i++)
		{
			if (readers == NULL) {
				readers = new reader;
				head = readers;
			}
			else
			{
				readers = readers->next = new reader;
				tail = readers;
			}

			inReaders.get();
			getline(inReaders, readers->data.surname);
			getline(inReaders, readers->data.name);
			getline(inReaders, readers->data.patronymic);
			getline(inReaders, readers->data.numberTicket);
			getline(inReaders, readers->data.booksName);
			getline(inReaders, readers->data.refundPeriod);
			inReaders >> readers->data.MaxRefundPeriod;
		}

		std::cout << "Операция завершена!";

		_getch();
		std::system("cls");
		break;
	}
	}
}
//загрузка
void fillreaders(reader* head, reader* tail, reader* readers, int* counter)
{
	string surnames[10] =		//вводим фамилии
	{
		"Лихачев",
		"Таргашина",
		"Мисюркеев",
		"Коковихин",
		"Ибрагимов",
		"Артамонов",
		"Казакина",
		"Немеров",
		"Дартан-Оол",
		"Гылыков"
	};
	string names[10] =			//имена
	{
		"Денис",
		"Екатерина",
		"Никита",
		"Андрей",
		"Джавидан",
		"Данил",
		"Анастасия",
		"Александр",
		"Чаян",
		"Гэсэр"
	};
	string patronymic[10] =		//отчества
	{
		"Отчество",
		"Отчество",
		"Отчество",
		"Отчество",
		"Отчество",
		"Отчество",
		"Отчество",
		"Отчество",
		"Отчество",
		"Отчество",
	};
	string numberTicket[10] =	//номера билетов
	{
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
	};
	string booksName[10] =		//названия книг
	{
		"Оно 1",
		"Оно 2",
		"Оно 3",
		"Оно 4",
		"Оно 5",
		"Оно 6",
		"Оно 7",
		"Оно 8",
		"Оно 9",
		"Оно 10"
	};
	string refundPeriod[10] =	//срок возврата
	{
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
	};
	int MaxRefundPeriod[10] =	//максимальный срок возврата
	{
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10,
		11,
	};

	readers->data.surname = surnames[0];			//записываем первого читателя на первое место в списке
	readers->data.name = names[0];
	readers->data.patronymic = patronymic[0];
	readers->data.numberTicket = numberTicket[0];
	readers->data.booksName = booksName[0];
	readers->data.refundPeriod = refundPeriod[0];
	readers->data.MaxRefundPeriod = MaxRefundPeriod[0];

	for (int i = 1; i < 10; i++)		//записываем остальные введенные данные в список
	{
		readers->next = new reader;
		readers->next->prev = readers;
		readers = readers->next;
		readers->data.surname = surnames[i];
		readers->data.name = names[i];
		readers->data.patronymic = patronymic[i];
		readers->data.numberTicket = numberTicket[i];
		readers->data.booksName = booksName[i];
		readers->data.refundPeriod = refundPeriod[i];
		readers->data.MaxRefundPeriod = MaxRefundPeriod[i];

		(*counter)++;		//увеличиваем счетчик кол-ва читателей
	}
}
//просто заполняет наш список
void addReaders(reader* readers, reader* tail, reader* head, int* counter)
{
	string	newSurname = { "None" };		//создаем переменные для записи данных
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newNumberTicket = { "None" };
	string	newBooksName = { "None" };
	string	newRefundPeriod = { "None" };
	int		newMaxRefundPeriod = 0;

	cout << "Фамилия: "; 			cin >> newSurname;			//вводим данные нового читателя
	cout << "Имя: ";				cin >> newName;
	cout << "Отчество: ";			cin >> newPatronymic;
	cout << "Номер билета: ";		cin >> newNumberTicket;
	cout << "Название книги: ";		cin >> newBooksName;
	cout << "Срок возврата: ";		cin >> newRefundPeriod;
	cout << "Макс. срок возврата: "; cin >> newMaxRefundPeriod;

	std::system("cls");

	readers = tail;												//записываем их в список
	readers->next = new reader;
	readers->next->prev = readers;
	readers = readers->next;
	readers->data.surname = newSurname;
	readers->data.name = newName;
	readers->data.patronymic = newPatronymic;
	readers->data.numberTicket = newNumberTicket;
	readers->data.booksName = newBooksName;
	readers->data.refundPeriod = newRefundPeriod;
	readers->data.MaxRefundPeriod = newMaxRefundPeriod;

	(*counter)++;		//увеличиваем счетчик кол-ва читателей

	std::system("cls");
}
//добавить нового читателя
void delreader(reader*& head, reader*& tail, reader*& readers, int* counter)
{
	if (readers != head && readers != tail)
	{
		readers->prev->next = readers->next;
		readers->next->prev = readers->prev;
	}
	else if (readers == head && readers != tail)
	{
		head = readers->next;
		head->prev = NULL;
	}
	else if (readers == tail && readers != head)
	{
		tail = readers->prev;
		tail->next = NULL;
	}
	else
	{
		head = NULL;
		tail = NULL;
	}
	delete readers;
	(*counter)--;
}
//вспомогательная функция (находится в deleteReaders)
void deleteReaders(reader* readers, reader* tail, reader* head, int* counter)
{
	readers = head;		//переходим к голове списка

	std::cout << "Введите фамилию или имя или отчество: ";		//вводим одно из предложенного
	string str; cin >> str;

	std::system("cls");

	int id = 1;		//нужные переменные для поиска в списке
	int search = -1;
	int Error = 0;

	while (true)
	{
		if (str == readers->data.surname)		//нужно чтобы выдать ошибку о совпадениях
		{										//или о том, что читатель не найден
			search = id;
			Error++;
		}
		if (str == readers->data.name)			//нужно чтобы выдать ошибку о совпадениях
		{										//или о том, что читатель не найден
			search = id;
			Error++;
		}
		if (str == readers->data.patronymic)	//нужно чтобы выдать ошибку о совпадениях
		{										//или о том, что читатель не найден
			search = id;
			Error++;
		}
		if (readers == tail)
			break;

		readers = readers->next;				//переход к следующему элементу

		id++;
	}

	if (Error > 1)			//найдены совпадения в имени, фамилии или отчестве
	{
		throw exception("Найдены совпадения, измените запрос");

		_getch();
		std::system("cls");

		return;
	}
	if (search == -1)		//не найден 
	{
		throw exception("Читатель не найден");

		_getch();
		std::system("cls");

		return;
	}
	if (search >= 0)				//переходим к поиску и удалению
	{
		readers = head;

		while (readers->next != NULL)		//ищем того, кто нам нужен
		{
			if (readers->data.surname == str || readers->data.name == str || readers->data.patronymic == str)		//ищем совпадения
			{
				break;		//если нашли совпадение выходим из цикла
			}
			readers = readers->next;		//если не нашли, идем дальше по списку
		}

		std::cout << "Удалить читателя ["		//убеждаемся, что хотим удалить
			<< readers->data.surname
			<< " " << readers->data.name
			<< " " << readers->data.patronymic
			<< "]\n1. Да\t2. Нет\n\nВыбор: ";

		int choice; cin >> choice;

		std::system("cls");

		switch (choice)
		{
		case(1):		//удаляем
		{
			delreader(head, tail, readers, counter);
			std::cout << "Операция завершена";

			_getch();
			std::system("cls");

			return;
		}
		case(2):		//отказываемся удалять
			return;
		}
	}
}
//удалить читателя
void showReaders(reader* readers, reader* tail, reader* head, int* counter)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\tНет данных клиентов для вывода...");

	int maxLenSurname = 7;                 //заранее прописываем длину (например слова имя, фамилия и т.д.)
	int maxLenName = 3;
	int maxLenPatronymic = 8;
	int maxLennumberTicket = 12;
	int maxLenbooksName = 14;
	int maxLenrefundPeriod = 13;
	int maxLenMaxRefundPeriod = 15;

	int maxMaxRefundPeriod = 0;

	readers = head;		//переходим к голове списка

	while (true)
	{
		int LenSurname = readers->data.surname.length();				//вычисляем длину каждого поля читателя
		int LenName = readers->data.name.length();
		int LenPatronymic = readers->data.patronymic.length();
		int LennumberTicket = readers->data.numberTicket.length();
		int LenbooksName = readers->data.booksName.length();
		int LenrefundPeriod = readers->data.refundPeriod.length();
		int LenMaxRefundPeriod = 0;
		int MaxRefundPeriod = readers->data.MaxRefundPeriod;
		int g = 0;
		while (MaxRefundPeriod > 0) { MaxRefundPeriod /= 10; LenMaxRefundPeriod++; }

		int sravn = readers->data.MaxRefundPeriod;    //вычисление максимального срока возрата
		for (int i = 0; i < *counter; i++)
		{
			if (sravn < readers->data.MaxRefundPeriod)
				sravn = readers->data.MaxRefundPeriod;
		}

		maxMaxRefundPeriod = sravn;

		if (LenSurname > maxLenSurname) { maxLenSurname = LenSurname; }							//сравниваем полученную длину с максимально возможной длиной этого столбца.
		if (LenName > maxLenName) { maxLenName = LenName; }										//если она полученная длина окажется больше максимальной,
		if (LenPatronymic > maxLenPatronymic) { maxLenPatronymic = LenPatronymic; }				//то приравниваем максимальную к полученной длине
		if (LennumberTicket > maxLennumberTicket) { maxLennumberTicket = LennumberTicket; }
		if (LenbooksName > maxLenbooksName) { maxLenbooksName = LenbooksName; }
		if (maxLenrefundPeriod > maxLenrefundPeriod) { maxLenrefundPeriod = maxLenrefundPeriod; }
		if (maxLenMaxRefundPeriod > maxLenMaxRefundPeriod) { maxLenMaxRefundPeriod = maxLenMaxRefundPeriod; }
		if (readers == tail)
			break;
		readers = readers->next;		//переход к следующему элементу
	}

	readers = head;		//переходим к голове списка

	int maxLength = maxLenSurname + maxLenName + maxLenPatronymic									//общая максимальная длина
		+ maxLennumberTicket + maxLenbooksName + maxLenrefundPeriod + maxLenMaxRefundPeriod + 22;	//нужна для отрисовки горизонтальных границ

	////////////////////////		ДАЛЕЕ ИДЕТ ПРОСТО ОТРИСОВКА ТАБЛИЦЫ		////////////////////////////

	std::cout << "\t";
	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << endl;

	printf_s("\t| %*s | %*s | %*s | %*s | %*s | %*s | %*s |",
		maxLenSurname, "Фамилия",
		maxLenName, "Имя",
		maxLenPatronymic, "Отчество",
		maxLennumberTicket, "Номер билета",
		maxLenbooksName, "Название книги",
		maxLenrefundPeriod, "День возврата",
		maxLenMaxRefundPeriod, "Max. возврат");
	std::cout << "\n\t";

	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << "\n";

	while (true) {
		printf_s(
			"\t| %*s | %*s | %*s | %*s | %*s | %*s | %*d |",
			maxLenSurname, readers->data.surname.c_str(),
			maxLenName, readers->data.name.c_str(),
			maxLenPatronymic, readers->data.patronymic.c_str(),
			maxLennumberTicket, readers->data.numberTicket.c_str(),
			maxLenbooksName, readers->data.booksName.c_str(),
			maxLenrefundPeriod, readers->data.refundPeriod.c_str(),
			maxLenMaxRefundPeriod, readers->data.MaxRefundPeriod
		);

		std::cout << "\n\t";

		for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
		std::cout << endl;
		if (readers->next == NULL) break;
		readers = readers->next;
	}
	readers = head;
	std::cout << "\t";
	for (int i = 0; i < maxLength - (maxLenrefundPeriod + 6); i++)
	{
		std::cout << " ";
	}
	printf_s("| %*d |", maxLenMaxRefundPeriod, maxMaxRefundPeriod); std::cout << "\n\t";
	for (int i = 0; i < maxLength - (maxLenrefundPeriod + 6); i++)
	{
		std::cout << " ";
	}
	for (int i = 0; i < maxLenrefundPeriod + 6; i++)
	{
		std::cout << "-";
	}


	_getch();
	std::system("cls");
}
//вывести список читателей
void transf(reader* readers, reader* tail, reader* head)
{
	std::cout << "Что вы хотите изменить?"										//выбор того, что мы хотим изменить
		<< "\n1) Фамилию [" << readers->data.surname
		<< "]\n2) Имя [" << readers->data.name
		<< "]\n3) Отчество [" << readers->data.patronymic
		<< "]\n4) Номер билета [" << readers->data.numberTicket
		<< "]\n5) Название книги [" << readers->data.booksName
		<< "]\n6) Срок возврата [" << readers->data.refundPeriod
		<< "]\n7) Максимальный срок возврата [" << readers->data.MaxRefundPeriod << "]\nВыбор: ";

	int choice;
	cin >> choice;

	switch (choice)											//собственно само изменение данных
	{
	case(1):
	{
		std::cout << "Введите Фамилию: ";
		cin.get();
		getline(cin, readers->data.surname);
		break;
	}
	case(2):
	{
		std::cout << "Введите Имя: ";
		cin.get();
		getline(cin, readers->data.name);
		break; }
	case(3):
	{
		std::cout << "Введите Отчество: ";
		cin.get();
		getline(cin, readers->data.patronymic);
		break; }
	case(4):
	{
		std::cout << "Введите Номер билета: ";
		cin.get();
		getline(cin, readers->data.numberTicket);
		break; }
	case(5):
	{
		std::cout << "Введите Название книги: ";
		cin.get();
		getline(cin, readers->data.booksName);
		break; }
	case(6):
	{
		std::cout << "Введите Срок возврата: ";
		cin.get();
		getline(cin, readers->data.refundPeriod);
		break; }
	case(7):
	{
		std::cout << "Введите Максимальный срок возврата: ";
		cin.get();
		cin >> readers->data.MaxRefundPeriod;
		break; }
	}
	std::system("cls");
}
//вспомогательная функция (находится в transformReaders)
void transformReaders(reader* readers, reader* tail, reader* head)
{
	if (tail == NULL && head == NULL)
		throw exception("\nНет данных клиентов для изменения...");

	readers = head;		//переходим к голове списка

	std::cout << "Введите фамилию или имя или отчество: ";

	string str; cin >> str;		//вводим данные для поиска читателя

	std::system("cls");

	int ID = -1;			//нужные переменные для поиска в списке
	int Error = 0;
	int id = 1;

	while (true)
	{
		if (readers->next == NULL)
			break;
		if (str == readers->data.surname)				//нужно чтобы выдать ошибку о совпадениях
		{												//или о том, что читатель не найден
			ID = id;
			Error++;
		}
		if (str == readers->data.name)					//нужно чтобы выдать ошибку о совпадениях
		{												//или о том, что читатель не найден
			ID = id;
			Error++;
		}
		if (str == readers->data.patronymic)			//нужно чтобы выдать ошибку о совпадениях
		{												//или о том, что читатель не найден
			ID = id;
			Error++;
		}

		readers = readers->next;

		id++;
	}
	if (Error > 1)			//найдены совпадения в имени, фамилии или отчестве
	{
		throw exception("\nНайдено более одного совпадения, введите дргуие даннные.");

		char p = _getch();
		std::system("cls");

		return;
	}
	if (ID == -1)			//не найден
	{
		throw exception("Читатель не найден");

		char p = _getch();
		std::system("cls");

		return;
	}
	if (ID >= 0)			//переходим к нахождению и изменению данных
	{
		readers = head;

		while (readers->next != NULL)		//ищем того, кто нам нужен
		{
			if (readers->data.surname == str || readers->data.name == str || readers->data.patronymic == str)		//ищем совпадения
			{
				break;		//если нашли совпадение выходим из цикла
			}
			readers = readers->next;		//если не нашли, идем дальше по списку
		}

		std::cout << "Изменить данные читателя ["		//убеждаемся, что хотим изменить данные
			<< readers->data.surname
			<< " " << readers->data.name
			<< " " << readers->data.patronymic
			<< "]\n1. Да\t2. Нет\nВыбор: ";

		int choice; cin >> choice;

		std::system("cls");

		switch (choice)					//изменияем данные
		{
		case(1):
		{
			transf(readers, tail, head);
			return;
		}
		case(2):					//отказываемся изменить данные
		{
			return;
		}
		}
	}

	std::system("cls");
}
//изменить данные читателя
void sortReaders(reader* readers, reader* tail, reader* head)
{

	if (tail == NULL && head == NULL)
		throw exception("\nНет данных для сортировки...");

	if (readers == head && readers == tail)
		throw exception("\nМало данных для сортировки...");


	std::cout << "Сортировка по\t1)Фамилии\t2)Имени";		//выбираем пункт, по которому будем сортировать

	int choice; cin >> choice;

	readers = head;			//переходим к голове списка

	int counter = 1;
	reader* temp = NULL;
	temp = new reader;

	while (true)		//считаем сколько у нас элементов списка
	{
		counter++;
		readers = readers->next;
		if (readers == tail)
			break;
	}

	readers = head;		//переходим к голове списка

	std::system("cls");

	switch (choice)
	{
	case(1):						//сортировка по фамилии
	{
		for (int i = 1; i < counter; i++)
		{
			readers = head;		//переходим к началу списка

			for (int j = 0; j < counter - i; j++)		//пузырьковый способ сортировки
			{
				if (readers->data.surname > readers->next->data.surname)
				{
					temp->data = readers->data;
					readers->data = readers->next->data;
					readers->next->data = temp->data;
				}
				readers = readers->next;		//переходим к следующему элементу
			}
		}
		std::cout << "Операция завершена";

		_getch();
		std::system("cls");

		return;
	}
	case(2):						//сортировка по имени
	{
		for (int i = 1; i < counter; i++)
		{
			readers = head;		//переходим к началу списка

			for (int j = 0; j < counter - i; j++)		//пузырьковый способ сортировки
			{
				if (readers->data.name > readers->next->data.name)
				{
					temp->data = readers->data;
					readers->data = readers->next->data;
					readers->next->data = temp->data;
				}
				readers = readers->next;		//переходим к следующему элементу
			}
		}
		std::cout << "Операция завершена";

		_getch();
		std::system("cls");

		return;
	}
	}
}
//сортировать читателей
void show(reader* readers)
{
	std::cout << "ФИО: " << readers->data.surname << " " << readers->data.name << " " << readers->data.patronymic
		<< "\nНомер билета: " << readers->data.numberTicket
		<< "\nНазвание книги: " << readers->data.booksName
		<< "\nСрок возврата: " << readers->data.refundPeriod
		<< "\nМаксимальный срок возварата: " << readers->data.MaxRefundPeriod;

	_getch();
	std::system("cls");
}
//вспомогательная функция (находится в searchReaders)
void searchReaders(reader* readers, reader* tail, reader* head)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\tНет данных клиентов для поиска...");

	std::cout << "Введите фамилию или имя или отчество: ";

	string str; cin >> str;

	std::system("cls");

	readers = head;				//переходим к началу списка
	bool result = false;		//нужно чтобы вывести сообщение об удачном или неудачном исходе

	while (true)
	{
		if (readers->next == NULL)				//ищем совпадение по запросу и выводим информацию об этом человеке
			break;								//(в функции show)
		if (str == readers->data.surname)
		{
			result = true;
			show(readers);
		}
		if (str == readers->data.name)
		{
			result = true;
			show(readers);
		}
		if (str == readers->data.patronymic)
		{
			result = true;
			show(readers);
		}
		readers = readers->next;
	}

	readers = head;		//переходим к началу списка

	if (result == true)
	{
		std::cout << "Операция завершена";

		_getch();
		std::system("cls");

		return;
	}
	if
		(result == false)
	{
		std::cout << "Клиент не найден";

		_getch();
		std::system("cls");

		return;
	}

	std::system("cls");
}
//поиск читателя