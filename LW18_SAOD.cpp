#include "conflictFree.h"
#include "internalHashing.h"
#include "openHashing.h"
#include "menu.h"



int main()
{
	setlocale(LC_ALL, "ru");
	srand(static_cast<unsigned int>(time(0)));
		   
	int operation{ -1 };
	bool keyRestart = true;
	std::string searchKey{ "error" };
	std::string newKey{ "error" };

	while (true) {
		printMenu(0);
		enteringNumber(0, 3, operation);
		switch (operation)
		{
		case 0:
			return 0;
		case 1: // lw 2.4.1
			initCFHashTable();
			while (keyRestart) {
				printMenu(1);
				enteringNumber(0, 3, operation);
				switch (operation)
				{
				case 0:
					keyRestart = false;
					break;
				case 1:
					for (int i = 0; i < 10; i++)
							addCF(arrayKeys[i]);
					break;
				case 2:
					if (hashTable == nullptr) std::cout << "Таблица пуста" << std::endl;
					else printTableCF();
					break;
				case 3:
					std::cout << "Какой ключ ищем >> " << std::endl;
					std::cin >> searchKey;
					searchCF(searchKey);
					break;
				default:
					break;
				}
			}
			break;
		case 2: // lw 2.4.2
			printMenu(3);
			enteringNumber(0, 5, operation);
			if (operation == 0) break;
			else if (operation == 1) size = 9;
			else if (operation == 2) size = 11;
			else if (operation == 3) size = 13;
			else if (operation == 4) size = 17;
			else if (operation == 5) size = 23;

			initIH(size); keyRestart = true;

			while (keyRestart) {
				printMenu(2);
				enteringNumber(0, 4, operation);
				
				switch (operation)
				{
				case 0: keyRestart = false;  break;
				case 1: 
					std::cout << "Какой ключ добавить >> " << std::endl;
					std::cin >> newKey;
					addIH(newKey);
					break;
				case 2:
					for (int i = 0; i < 10; i++) {
						int randIndex = rand() % 30;
						addIH(surnames[randIndex]);
					}
					break;
				case 3:
					std::cout << "Какой ключ найти >> " << std::endl;
					std::cin >> searchKey;
					searchIH(searchKey);
					break;
				case 4:
					if (hashTableIH == nullptr) std::cout << "Таблица пуста" << std::endl;
					else printTableIH();
					break;
				default:
					break;
				}
			}

			break;
		case 3: // lw 2.4.3
			printMenu(3);
			enteringNumber(0, 5, operation);
			if (operation == 0) break;
			else if (operation == 1) sizeOH = 9;
			else if (operation == 2) sizeOH = 11;
			else if (operation == 3) sizeOH = 13;
			else if (operation == 4) sizeOH = 17;
			else if (operation == 5) sizeOH = 23;
			initOH(sizeOH); keyRestart = true;

			while (keyRestart) {
				printMenu(4);
				enteringNumber(0,5, operation);

				switch (operation)
				{
				case 0: keyRestart = false; break;
				case 1:
					std::cout << "Какой ключ добавить >> " << std::endl;
					std::cin >> newKey;
					addOH(newKey);
					break;
				case 2:
					for (int i = 0; i < 20; i++) {
						int randIndex = rand() % 30;
						addOH(surnames[randIndex]);
					}
					break;
				case 3:
					std::cout << "Какой ключ найти >> " << std::endl;
					std::cin >> searchKey;
					searchKeyOH(searchKey)? std::cout << " Ключ найден" << std::endl 
						: std::cout << " Такого ключа в таблице нет" << std::endl;
					break;
				case 4:
					std::cout << "Какой ключ удалить >> " << std::endl;
					std::cin >> searchKey;
					deleteKeyOH(searchKey);
					break;
				case 5:
					if (hashTableOH == nullptr) std::cout << "Таблица пуста " << std::endl;
					else printOpenHashTable();
					break;
				default:
					break;
				}
			}

			break;
		default:
			break;
		}
	}
}

