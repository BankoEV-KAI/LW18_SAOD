#include "menu.h"
#include <iostream>


void printMenu(int operation) {


    switch (operation)
    {
    case 0:
        std::cout << "Выбор номера ЛР (метода хеширования)" << std::endl
            << "1 - 2.4.1 Безконфликтная хеш-таблица " << std::endl
            << "2 - 2.4.2 Метод внутреннего хеширования " << std::endl
            << "3 - 2.4.3 Метод открытого хеширования " << std::endl
            << "0 - завершение работы " << std::endl;
        break;
    case 1:
        std::cout << "Безконфликтная хеш-таблица (слова языка Паскаль)" << std::endl
            << "1 - Заполенение таблицы элементами " << std::endl
            << "2 - Вывод хеш-таблицы " << std::endl
            << "3 - Поиск элемента " << std::endl
            << "0 - назад" << std::endl;
        break;
    case 2:
        std::cout << "Метод внутреннего хеширования " << std::endl
            << "1 - Добавление одного нового ключа" << std::endl
            << "2 - Добвление нескольких ключей (из заготовленного массива)" << std::endl
            << "3 - Поиск ключа" << std::endl
            << "4 - Текущее состояние таблицы" << std::endl
            << "0 - назад" << std::endl;
        break;
    case 3:
        std::cout << "Выбор размерности таблицы" << std::endl
            << "1 - 9 элементов" << std::endl
            << "2 - 11 элементов " << std::endl
            << "3 - 13 элементво" << std::endl
            << "4 - 17 элементов" << std::endl
            << "5 - 23 элементов" << std::endl
            << "0 - назад" << std::endl;
        break;
    case 4:
        std::cout << "Метод открытого хеширования" << std::endl
            << "1 - добавление одного ключа" << std::endl
            << "2 - Добвление нескольких ключей (из заготовленного массива)" << std::endl
            << "3 - Поиск ключа" << std::endl
            << "4 - Удаление ключа" << std::endl
            << "5 - Текущее состояние таблицы" << std::endl
            << "0 - назад" << std::endl;
        break;
    default:
        break;
    }
}

void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от " << rangeStart << " до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}
