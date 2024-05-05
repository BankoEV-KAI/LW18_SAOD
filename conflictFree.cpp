
#include "conflictFree.h"

std::string* hashTable = nullptr;
std::string arrayKeys[]{ "program", "var", "begin", "end", "read", "write", "start", "with", "nil", "file" };

void initCFHashTable() {
    if (hashTable != nullptr) delete[] hashTable;
    hashTable = new std::string[10];
}

int getHashCF(std::string key) {
    int hash{ 0 };
    for (int i = 0; i < key.size(); i++)
        hash += (int)key[i];
    hash %= 10;
    return hash;
}

std::string getKeyCF(int hash) {
    return hashTable[hash];
}

void printTableCF() {
    std::cout << "Формат записи значений hash:key, hash:пусто говороит, что не присвоено значение ключа" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << ":" << getKeyCF(i) << std::endl;
    }
}

void addCF(std::string key) {
    if (hashTable[getHashCF(key)].empty()) {
        hashTable[getHashCF(key)] = key;
        std::cout << "Ключ " << key << " добавлен в ячейку " << getHashCF(key) << std::endl;
    }
    else std::cout << "ячейка " << getHashCF(key) << " занята другим или тем же ключом" << std::endl;
}

void searchCF(std::string key) {
    int hash = getHashCF(key);
    if (hashTable[hash] == key) std::cout << "Элемент с ключом " << key << " найден на позиции " << hash << std::endl;
    else std::cout << "Элемент с ключом " << key << " в таблице не найден " << std::endl;
}

bool enteringKeyCF(std::string key) {
    for (int i = 0; i < 10; i++) {
        if (key == arrayKeys[i]) return true;
    }
    return false;
}