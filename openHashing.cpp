#include "openHashing.h"


int sizeOH{ 0};
Node** hashTableOH {nullptr };

void initOH(int size) {
    hashTableOH = new Node * [size];
    sizeOH = size;
    for (int i = 0; i < sizeOH; i++) 
        hashTableOH[i] = nullptr;
    std::cout << "Была инициализированна пустая таблица размерностью " << size << " элементов " << std::endl;
}

int getHashOH(std::string key) {
    int hash{ 0 };
    for (int i = 0; i < key.size(); i++)
        hash += (int)key[i];
    hash %= sizeOH;
    std::cout << "Определение хеша для ключа " << key << ":" << hash << std::endl;
    return hash;
}

void addOH(std::string newKey) {
	comparisons = 0;
	int hash = getHashOH(newKey);
    Node* newNode = new Node{ newKey, nullptr };

    if (hashTableOH[hash] == nullptr) {
        hashTableOH[hash] = newNode;
    }
    else {
        Node* current = hashTableOH[hash];
        while (current->next != nullptr) {
            current = current->next;
            comparisons++;
        }
        current->next = newNode;
    }
    std::cout << "Элемент с ключом " << newKey << " добавлен в таблицу под индексом " << hash << std::endl;
}

bool searchKeyOH(const std::string key) {
    comparisons = 0;
    int index = getHashOH(key);
    Node* current = hashTableOH[index];
    while (current != nullptr) {
        comparisons++;
        if (current->key == key) {
            return true; // ключ найден
        }
        current = current->next;
    }
    return false; // ключ не найден
}

void deleteKeyOH(const std::string& key) {
    int index = getHashOH(key);
    Node* current = hashTableOH[index];
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                hashTableOH[index] = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    std::cout << "Ключ не найден и не удален " << key <<std::endl;
}

void printOpenHashTable() {
    std::cout << "Формат записи значений hash:key, hash:пусто говороит, что не присвоено значение ключа" << std::endl;

    for (int i = 0; i < sizeOH; ++i) {
        std::cout << i << ": ";
        Node* current = hashTableOH[i];
        while (current != nullptr) {
            std::cout << current->key << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

void demonstrationOH(int sizeTable) {
    /* взять 10 ключей и разместить их поочередно в таблице размерности 11, 13 и 17.*/
    int countStartItems = 10;
    switch (sizeTable)
    {
    case 11:
        initOH(11);
        break;
    case 13:
        initOH(13);
        break;
    case 17:
        initOH(17);
        break;
    default:
        return;
    }
    std::cout << "Добавление " << countStartItems << " элементов в таблицу " << std::endl;
    for (int i = 0; i < countStartItems; ++i)
        addOH(surnames[i]);

    printOpenHashTable();

}