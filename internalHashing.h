#pragma once
#include "conflictFree.h"

extern std::string* hashTableIH;
extern std::string surnames[30];
extern int size;
extern int comparisons;


void initIH(int _size);

int getHash(std::string key);

void addIH(std::string newKey);

void searchIH(std::string key);

void printTableIH();


