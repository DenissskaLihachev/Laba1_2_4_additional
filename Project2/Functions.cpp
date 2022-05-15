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
		throw exception("\n��� ������ ��� ����������...");

	string defaultFile = ("SaveReaders.txt");
	string individualFile;

	cout << "1) ��������� � ����� �� ��������� (SaveReaders.txt)\t2) ��������� � ����� �����\n\n�����: "; int choice; cin >> choice;

	std::system("cls");

	switch (choice)
	{
	case(1):
	{
		ofstream saveReaders("SaveReaders.txt");

		readers = head;

		while (true)
		{
			saveReaders << "���: " << readers->data.surname << " " << readers->data.name << " " << readers->data.patronymic << " ����� ������: " << readers->data.numberTicket << " �������� �����: " << readers->data.booksName << " ���� ��������: " << readers->data.refundPeriod << " Max. �������: " << readers->data.MaxRefundPeriod << endl;

			if (readers == tail)
				break;
			readers = readers->next;
		}
		cout << "�������� ���������!";

		saveReaders.close();

		_getch();
		std::system("cls");
		break;
	}
	case(2):
	{
		cout << "������� �������� ����� (� ����������� '.txt'): "; cin >> individualFile;

		std::system("cls");

		ofstream saveReaders(individualFile);

		readers = head;

		while (true)
		{
			saveReaders << "���: " << readers->data.surname << " " << readers->data.name << " " << readers->data.patronymic << " ������: " << readers->data.numberTicket << " ����� ���.: " << readers->data.booksName << " ���� ������: " << readers->data.refundPeriod << " �����: " << readers->data.MaxRefundPeriod << endl;

			if (readers == tail)
				break;
			readers = readers->next;
		}
		cout << "�������� ���������!";

		saveReaders.close();

		_getch();
		std::system("cls");
		break;
	}
	}
}
//����������
void load(reader* readers, reader* tail, reader* head)
{
	string defaultFile = ("SaveReaders.txt");
	string individualFile;
	std::cout << "1) ��������� �� ����� �� ���������\t2) ��������� �� ������ �����\n\n�����: ";
	int inNum;
	cin >> inNum;
	std::system("cls");
	switch (inNum)
	{
	case(1):
	{
		ifstream inputReaders("SaveReaders.txt");

		if (inputReaders.bad())
			throw exception("\n\t������ �����-������ ��� ������");

		if (inputReaders.eof())
			throw exception("\n\t��������� ����� �����");

		if (inputReaders.fail())
			throw exception("\n\t�������� ������ ������");


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

		std::cout << "�������� ���������!";

		_getch();
		std::system("cls");
		break;
	}
	case(2):
	{
		std::cout << "������� �������� ����� (� ����������� '.txt'): "; cin >> individualFile;

		std::system("cls");

		ifstream inReaders(individualFile);

		if (inReaders.bad())
			throw exception("\n\t������ �����-������ ��� ������");


		if (inReaders.eof())
			throw exception("\n\t��������� ����� �����");


		if (inReaders.fail())
			throw exception("\n\t�������� ������ ������");

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

		std::cout << "�������� ���������!";

		_getch();
		std::system("cls");
		break;
	}
	}
}
//��������
void fillreaders(reader* head, reader* tail, reader* readers, int* counter)
{
	string surnames[10] =		//������ �������
	{
		"�������",
		"���������",
		"���������",
		"���������",
		"���������",
		"���������",
		"��������",
		"�������",
		"������-���",
		"�������"
	};
	string names[10] =			//�����
	{
		"�����",
		"���������",
		"������",
		"������",
		"��������",
		"�����",
		"���������",
		"���������",
		"����",
		"�����"
	};
	string patronymic[10] =		//��������
	{
		"��������",
		"��������",
		"��������",
		"��������",
		"��������",
		"��������",
		"��������",
		"��������",
		"��������",
		"��������",
	};
	string numberTicket[10] =	//������ �������
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
	string booksName[10] =		//�������� ����
	{
		"��� 1",
		"��� 2",
		"��� 3",
		"��� 4",
		"��� 5",
		"��� 6",
		"��� 7",
		"��� 8",
		"��� 9",
		"��� 10"
	};
	string refundPeriod[10] =	//���� ��������
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
	int MaxRefundPeriod[10] =	//������������ ���� ��������
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

	readers->data.surname = surnames[0];			//���������� ������� �������� �� ������ ����� � ������
	readers->data.name = names[0];
	readers->data.patronymic = patronymic[0];
	readers->data.numberTicket = numberTicket[0];
	readers->data.booksName = booksName[0];
	readers->data.refundPeriod = refundPeriod[0];
	readers->data.MaxRefundPeriod = MaxRefundPeriod[0];

	for (int i = 1; i < 10; i++)		//���������� ��������� ��������� ������ � ������
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

		(*counter)++;		//����������� ������� ���-�� ���������
	}
}
//������ ��������� ��� ������
void addReaders(reader* readers, reader* tail, reader* head, int* counter)
{
	string	newSurname = { "None" };		//������� ���������� ��� ������ ������
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newNumberTicket = { "None" };
	string	newBooksName = { "None" };
	string	newRefundPeriod = { "None" };
	int		newMaxRefundPeriod = 0;

	cout << "�������: "; 			cin >> newSurname;			//������ ������ ������ ��������
	cout << "���: ";				cin >> newName;
	cout << "��������: ";			cin >> newPatronymic;
	cout << "����� ������: ";		cin >> newNumberTicket;
	cout << "�������� �����: ";		cin >> newBooksName;
	cout << "���� ��������: ";		cin >> newRefundPeriod;
	cout << "����. ���� ��������: "; cin >> newMaxRefundPeriod;

	std::system("cls");

	readers = tail;												//���������� �� � ������
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

	(*counter)++;		//����������� ������� ���-�� ���������

	std::system("cls");
}
//�������� ������ ��������
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
//��������������� ������� (��������� � deleteReaders)
void deleteReaders(reader* readers, reader* tail, reader* head, int* counter)
{
	readers = head;		//��������� � ������ ������

	std::cout << "������� ������� ��� ��� ��� ��������: ";		//������ ���� �� �������������
	string str; cin >> str;

	std::system("cls");

	int id = 1;		//������ ���������� ��� ������ � ������
	int search = -1;
	int Error = 0;

	while (true)
	{
		if (str == readers->data.surname)		//����� ����� ������ ������ � �����������
		{										//��� � ���, ��� �������� �� ������
			search = id;
			Error++;
		}
		if (str == readers->data.name)			//����� ����� ������ ������ � �����������
		{										//��� � ���, ��� �������� �� ������
			search = id;
			Error++;
		}
		if (str == readers->data.patronymic)	//����� ����� ������ ������ � �����������
		{										//��� � ���, ��� �������� �� ������
			search = id;
			Error++;
		}
		if (readers == tail)
			break;

		readers = readers->next;				//������� � ���������� ��������

		id++;
	}

	if (Error > 1)			//������� ���������� � �����, ������� ��� ��������
	{
		throw exception("������� ����������, �������� ������");

		_getch();
		std::system("cls");

		return;
	}
	if (search == -1)		//�� ������ 
	{
		throw exception("�������� �� ������");

		_getch();
		std::system("cls");

		return;
	}
	if (search >= 0)				//��������� � ������ � ��������
	{
		readers = head;

		while (readers->next != NULL)		//���� ����, ��� ��� �����
		{
			if (readers->data.surname == str || readers->data.name == str || readers->data.patronymic == str)		//���� ����������
			{
				break;		//���� ����� ���������� ������� �� �����
			}
			readers = readers->next;		//���� �� �����, ���� ������ �� ������
		}

		std::cout << "������� �������� ["		//����������, ��� ����� �������
			<< readers->data.surname
			<< " " << readers->data.name
			<< " " << readers->data.patronymic
			<< "]\n1. ��\t2. ���\n\n�����: ";

		int choice; cin >> choice;

		std::system("cls");

		switch (choice)
		{
		case(1):		//�������
		{
			delreader(head, tail, readers, counter);
			std::cout << "�������� ���������";

			_getch();
			std::system("cls");

			return;
		}
		case(2):		//������������ �������
			return;
		}
	}
}
//������� ��������
void showReaders(reader* readers, reader* tail, reader* head, int* counter)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ������...");

	int maxLenSurname = 7;                 //������� ����������� ����� (�������� ����� ���, ������� � �.�.)
	int maxLenName = 3;
	int maxLenPatronymic = 8;
	int maxLennumberTicket = 12;
	int maxLenbooksName = 14;
	int maxLenrefundPeriod = 13;
	int maxLenMaxRefundPeriod = 15;

	int maxMaxRefundPeriod = 0;

	readers = head;		//��������� � ������ ������

	while (true)
	{
		int LenSurname = readers->data.surname.length();				//��������� ����� ������� ���� ��������
		int LenName = readers->data.name.length();
		int LenPatronymic = readers->data.patronymic.length();
		int LennumberTicket = readers->data.numberTicket.length();
		int LenbooksName = readers->data.booksName.length();
		int LenrefundPeriod = readers->data.refundPeriod.length();
		int LenMaxRefundPeriod = 0;
		int MaxRefundPeriod = readers->data.MaxRefundPeriod;
		int g = 0;
		while (MaxRefundPeriod > 0) { MaxRefundPeriod /= 10; LenMaxRefundPeriod++; }

		int sravn = readers->data.MaxRefundPeriod;    //���������� ������������� ����� �������
		for (int i = 0; i < *counter; i++)
		{
			if (sravn < readers->data.MaxRefundPeriod)
				sravn = readers->data.MaxRefundPeriod;
		}

		maxMaxRefundPeriod = sravn;

		if (LenSurname > maxLenSurname) { maxLenSurname = LenSurname; }							//���������� ���������� ����� � ����������� ��������� ������ ����� �������.
		if (LenName > maxLenName) { maxLenName = LenName; }										//���� ��� ���������� ����� �������� ������ ������������,
		if (LenPatronymic > maxLenPatronymic) { maxLenPatronymic = LenPatronymic; }				//�� ������������ ������������ � ���������� �����
		if (LennumberTicket > maxLennumberTicket) { maxLennumberTicket = LennumberTicket; }
		if (LenbooksName > maxLenbooksName) { maxLenbooksName = LenbooksName; }
		if (maxLenrefundPeriod > maxLenrefundPeriod) { maxLenrefundPeriod = maxLenrefundPeriod; }
		if (maxLenMaxRefundPeriod > maxLenMaxRefundPeriod) { maxLenMaxRefundPeriod = maxLenMaxRefundPeriod; }
		if (readers == tail)
			break;
		readers = readers->next;		//������� � ���������� ��������
	}

	readers = head;		//��������� � ������ ������

	int maxLength = maxLenSurname + maxLenName + maxLenPatronymic									//����� ������������ �����
		+ maxLennumberTicket + maxLenbooksName + maxLenrefundPeriod + maxLenMaxRefundPeriod + 22;	//����� ��� ��������� �������������� ������

	////////////////////////		����� ���� ������ ��������� �������		////////////////////////////

	std::cout << "\t";
	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << endl;

	printf_s("\t| %*s | %*s | %*s | %*s | %*s | %*s | %*s |",
		maxLenSurname, "�������",
		maxLenName, "���",
		maxLenPatronymic, "��������",
		maxLennumberTicket, "����� ������",
		maxLenbooksName, "�������� �����",
		maxLenrefundPeriod, "���� ��������",
		maxLenMaxRefundPeriod, "Max. �������");
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
//������� ������ ���������
void transf(reader* readers, reader* tail, reader* head)
{
	std::cout << "��� �� ������ ��������?"										//����� ����, ��� �� ����� ��������
		<< "\n1) ������� [" << readers->data.surname
		<< "]\n2) ��� [" << readers->data.name
		<< "]\n3) �������� [" << readers->data.patronymic
		<< "]\n4) ����� ������ [" << readers->data.numberTicket
		<< "]\n5) �������� ����� [" << readers->data.booksName
		<< "]\n6) ���� �������� [" << readers->data.refundPeriod
		<< "]\n7) ������������ ���� �������� [" << readers->data.MaxRefundPeriod << "]\n�����: ";

	int choice;
	cin >> choice;

	switch (choice)											//���������� ���� ��������� ������
	{
	case(1):
	{
		std::cout << "������� �������: ";
		cin.get();
		getline(cin, readers->data.surname);
		break;
	}
	case(2):
	{
		std::cout << "������� ���: ";
		cin.get();
		getline(cin, readers->data.name);
		break; }
	case(3):
	{
		std::cout << "������� ��������: ";
		cin.get();
		getline(cin, readers->data.patronymic);
		break; }
	case(4):
	{
		std::cout << "������� ����� ������: ";
		cin.get();
		getline(cin, readers->data.numberTicket);
		break; }
	case(5):
	{
		std::cout << "������� �������� �����: ";
		cin.get();
		getline(cin, readers->data.booksName);
		break; }
	case(6):
	{
		std::cout << "������� ���� ��������: ";
		cin.get();
		getline(cin, readers->data.refundPeriod);
		break; }
	case(7):
	{
		std::cout << "������� ������������ ���� ��������: ";
		cin.get();
		cin >> readers->data.MaxRefundPeriod;
		break; }
	}
	std::system("cls");
}
//��������������� ������� (��������� � transformReaders)
void transformReaders(reader* readers, reader* tail, reader* head)
{
	if (tail == NULL && head == NULL)
		throw exception("\n��� ������ �������� ��� ���������...");

	readers = head;		//��������� � ������ ������

	std::cout << "������� ������� ��� ��� ��� ��������: ";

	string str; cin >> str;		//������ ������ ��� ������ ��������

	std::system("cls");

	int ID = -1;			//������ ���������� ��� ������ � ������
	int Error = 0;
	int id = 1;

	while (true)
	{
		if (readers->next == NULL)
			break;
		if (str == readers->data.surname)				//����� ����� ������ ������ � �����������
		{												//��� � ���, ��� �������� �� ������
			ID = id;
			Error++;
		}
		if (str == readers->data.name)					//����� ����� ������ ������ � �����������
		{												//��� � ���, ��� �������� �� ������
			ID = id;
			Error++;
		}
		if (str == readers->data.patronymic)			//����� ����� ������ ������ � �����������
		{												//��� � ���, ��� �������� �� ������
			ID = id;
			Error++;
		}

		readers = readers->next;

		id++;
	}
	if (Error > 1)			//������� ���������� � �����, ������� ��� ��������
	{
		throw exception("\n������� ����� ������ ����������, ������� ������ �������.");

		char p = _getch();
		std::system("cls");

		return;
	}
	if (ID == -1)			//�� ������
	{
		throw exception("�������� �� ������");

		char p = _getch();
		std::system("cls");

		return;
	}
	if (ID >= 0)			//��������� � ���������� � ��������� ������
	{
		readers = head;

		while (readers->next != NULL)		//���� ����, ��� ��� �����
		{
			if (readers->data.surname == str || readers->data.name == str || readers->data.patronymic == str)		//���� ����������
			{
				break;		//���� ����� ���������� ������� �� �����
			}
			readers = readers->next;		//���� �� �����, ���� ������ �� ������
		}

		std::cout << "�������� ������ �������� ["		//����������, ��� ����� �������� ������
			<< readers->data.surname
			<< " " << readers->data.name
			<< " " << readers->data.patronymic
			<< "]\n1. ��\t2. ���\n�����: ";

		int choice; cin >> choice;

		std::system("cls");

		switch (choice)					//��������� ������
		{
		case(1):
		{
			transf(readers, tail, head);
			return;
		}
		case(2):					//������������ �������� ������
		{
			return;
		}
		}
	}

	std::system("cls");
}
//�������� ������ ��������
void sortReaders(reader* readers, reader* tail, reader* head)
{

	if (tail == NULL && head == NULL)
		throw exception("\n��� ������ ��� ����������...");

	if (readers == head && readers == tail)
		throw exception("\n���� ������ ��� ����������...");


	std::cout << "���������� ��\t1)�������\t2)�����";		//�������� �����, �� �������� ����� �����������

	int choice; cin >> choice;

	readers = head;			//��������� � ������ ������

	int counter = 1;
	reader* temp = NULL;
	temp = new reader;

	while (true)		//������� ������� � ��� ��������� ������
	{
		counter++;
		readers = readers->next;
		if (readers == tail)
			break;
	}

	readers = head;		//��������� � ������ ������

	std::system("cls");

	switch (choice)
	{
	case(1):						//���������� �� �������
	{
		for (int i = 1; i < counter; i++)
		{
			readers = head;		//��������� � ������ ������

			for (int j = 0; j < counter - i; j++)		//����������� ������ ����������
			{
				if (readers->data.surname > readers->next->data.surname)
				{
					temp->data = readers->data;
					readers->data = readers->next->data;
					readers->next->data = temp->data;
				}
				readers = readers->next;		//��������� � ���������� ��������
			}
		}
		std::cout << "�������� ���������";

		_getch();
		std::system("cls");

		return;
	}
	case(2):						//���������� �� �����
	{
		for (int i = 1; i < counter; i++)
		{
			readers = head;		//��������� � ������ ������

			for (int j = 0; j < counter - i; j++)		//����������� ������ ����������
			{
				if (readers->data.name > readers->next->data.name)
				{
					temp->data = readers->data;
					readers->data = readers->next->data;
					readers->next->data = temp->data;
				}
				readers = readers->next;		//��������� � ���������� ��������
			}
		}
		std::cout << "�������� ���������";

		_getch();
		std::system("cls");

		return;
	}
	}
}
//����������� ���������
void show(reader* readers)
{
	std::cout << "���: " << readers->data.surname << " " << readers->data.name << " " << readers->data.patronymic
		<< "\n����� ������: " << readers->data.numberTicket
		<< "\n�������� �����: " << readers->data.booksName
		<< "\n���� ��������: " << readers->data.refundPeriod
		<< "\n������������ ���� ���������: " << readers->data.MaxRefundPeriod;

	_getch();
	std::system("cls");
}
//��������������� ������� (��������� � searchReaders)
void searchReaders(reader* readers, reader* tail, reader* head)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ������...");

	std::cout << "������� ������� ��� ��� ��� ��������: ";

	string str; cin >> str;

	std::system("cls");

	readers = head;				//��������� � ������ ������
	bool result = false;		//����� ����� ������� ��������� �� ������� ��� ��������� ������

	while (true)
	{
		if (readers->next == NULL)				//���� ���������� �� ������� � ������� ���������� �� ���� ��������
			break;								//(� ������� show)
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

	readers = head;		//��������� � ������ ������

	if (result == true)
	{
		std::cout << "�������� ���������";

		_getch();
		std::system("cls");

		return;
	}
	if
		(result == false)
	{
		std::cout << "������ �� ������";

		_getch();
		std::system("cls");

		return;
	}

	std::system("cls");
}
//����� ��������