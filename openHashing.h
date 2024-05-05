#pragma once
#include "internalHashing.h"

extern  int sizeOH;

struct Node {
    std::string key;
    Node* next;
};

extern Node** hashTableOH;


void initOH(int size);

int getHashOH(std::string key);

void addOH(std::string newKey);

bool searchKeyOH(const std::string key);

void deleteKeyOH(const std::string& key);

void printOpenHashTable();

void demonstrationOH(int sizeTable);

