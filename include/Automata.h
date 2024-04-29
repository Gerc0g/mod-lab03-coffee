// Copyright 2022 UNN-IASR
// Automata.h

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;  // сумма
    std::vector<std::string> menu;  // Меню напитков
    std::vector<int> prices;  // Цены напитков
    STATES state;  // Текущее состояние автомата

 public:
    Automata();  // Конструктор

    void on();  // Включение
    void off();  // Выключение
    void coin(int amount);  // Занесение денег
    std::vector<std::string> getMenu();  // Считывание меню
    STATES getState();  // Считывание состояния
    void choice(int drink);  // Выбор напитка
    void check();  // Проверка наличия необходимой суммы
    void cancel();  // Отмена сеанса
    void cook();  // Имитация процесса приготовления напитка
    void finish();  // Завершение обслуживания пользователя
};

#endif // INCLUDE_AUTOMATA_H_
