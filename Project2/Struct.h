#pragma once

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

struct reader
{
	reader* next = NULL;		//��������� �� ��������� �������
	reader* prev = NULL;		//��������� �� ���������� �������
	struct
	{
		string surname;
		string name;
		string patronymic;
		string numberTicket;
		string booksName;
		string refundPeriod;
		int MaxRefundPeriod = 0;
	}data;
};