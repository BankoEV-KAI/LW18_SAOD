#include "internalHashing.h"
#include <fstream>

std::string* hashTableIH = nullptr;
int comparisons{ 0 };
int size{ 0 };

std::string surnames[30] = {
        "Smith", "Johnson", "Williams", "Brown", "Jones",
        "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
        "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson",
        "Thomas", "Taylor", "Moore", "Jackson", "Martin",
        "Lee", "Perez", "Thompson", "White", "Harris",
        "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson"
};

void initIH(int _size) {
    if (hashTableIH != nullptr) delete[] hashTableIH;
    hashTableIH = new std::string[_size];
    size = _size;
}

int getHash(std::string key) {
    int hash{ 0 };
    for (int i = 0; i < key.size(); i++)
        hash += (int)key[i];
    hash %= size;
    std::cout << "ќпределение хеша дл¤ ключа " << key << ":" << hash << std::endl;
    return hash;
}

void addIH(std::string newKey) {
    comparisons = 0;
    int hash = getHash(newKey);
    if (hashTableIH[hash].empty() || hashTableIH[hash] == newKey) {
        if (hashTableIH[hash] == newKey) {
            std::cout << "Ёлмент "<< newKey << " на позиции " << hash << " уже существовал" << std::endl;
            return;
        }
        hashTableIH[hash] = newKey;
        std::cout << "Ёлемент с ключом " << newKey << " добавлен на позицию " << hash << " с одним сравнением" << std::endl;
        return;
    }
    else {
        int newHash{ -1 };
        for (int i = 0; i < size-2; i++) {
            comparisons++;
            newHash = ((hash + i) & size) + 1;
            std::cout << "newHash " << newKey << ":" << newHash << std::endl;
            if (hashTableIH[newHash].empty() || hashTableIH[newHash] == newKey) {
                hashTableIH[newHash] = newKey;
                std::cout << "Ёлемент с ключом " << newKey << " добавлен на позицию " << newHash << ", количество сравнений: " << ++comparisons << std::endl;
                return;
            }
        }
        std::cout << "Ёлемент добавить невозможно: нет свободных мест дл¤ данного ключа" << std::endl;
    }
}


void searchIH(std::string key){
    comparisons = 0;
    int hash = getHash(key);
    if (hashTableIH[hash].empty()) {
        std::cout << "»скомый элемент отсутствует " << std::endl;
        return;
    }
    else {
        if (hashTableIH[hash] == key) {
            std::cout << " люч найден на позиции " << hash << ", за одно сравнение " << std::endl;
        }
        else {
            int newHash{ -1 };
            for (int i = 0; i < size - 2; i++) {
                comparisons++;
                newHash = ((hash + i) & size) + 1;
                if (hashTableIH[newHash] == key) {
                    std::cout << " люч найден на позиции " << hash << ", количество сравнений: "<< comparisons << std::endl;
                    return;
                }
            }
            std::cout << "Ёлемент не найден, количество произведенных сравнений: " << comparisons << std::endl;
        }
    }
}

void printTableIH() {
    std::cout << "‘ормат записи значений hash:key, hash:пусто говороит, что не присвоено значение ключа" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i << ":" << hashTableIH[i] << std::endl;
    }
}


