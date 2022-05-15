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
	reader* next = NULL;		//указатель на следующий элемент
	reader* prev = NULL;		//указатель на предыдущий элемент
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