#pragma once

#include <iostream>
#include <string>

extern std::string arrayKeys[10];

extern std::string* hashTable;

void initCFHashTable();

int getHashCF(std::string key);

std::string getKeyCF(int hash);

void printTableCF();

void addCF(std::string key);

void searchCF(std::string key);

bool enteringKeyCF(std::string key);
