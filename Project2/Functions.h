#pragma once

#include "Struct.h"

void save(reader* readers, reader* tail, reader* head);
void load(reader* readers, reader* tail, reader* head);
void fillreaders(reader* head, reader* tail, reader* readers, int* counter);
void addReaders(reader* readers, reader* tail, reader* head, int* counter);
void delreader(reader*& head, reader*& tail, reader*& readers, int* counter);
void deleteReaders(reader* readers, reader* tail, reader* head, int* counter);
void showReaders(reader* readers, reader* tail, reader* head, int* counter);
void transf(reader* readers, reader* tail, reader* head);
void transformReaders(reader* readers, reader* tail, reader* head);
void sortReaders(reader* readers, reader* tail, reader* head);
void show(reader* readers);
void searchReaders(reader* readers, reader* tail, reader* head);