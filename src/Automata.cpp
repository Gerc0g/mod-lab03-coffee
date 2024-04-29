// Copyright 2022 UNN-IASR
// Automata.cpp
#include "Automata.h"
#include <iostream>

Automata::Automata() {
    state = OFF;
    // Загрузка меню и цен из файла или инициализация прямо здесь
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Автомат включен." << std::endl;
    }
}

void Automata::off() {
    state = OFF;
    std::cout << "Автомат выключен." << std::endl;
}

void Automata::coin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        cash += amount;
        state = ACCEPT;
        std::cout << "Вы внесли " << amount << " единиц валюты." << std::endl;
    }
}

std::vector<std::string> Automata::getMenu() {
    // Возврат меню для пользователя
    return menu;
}

STATES Automata::getState() {
    // Возврат текущего состояния для пользователя
    return state;
}

void Automata::choice(int drink) {
    if (state == ACCEPT && drink >= 0 && drink < menu.size()) {
        if (cash >= prices[drink]) {
            state = CHECK;
            std::cout << "Вы выбрали: " << menu[drink] << std::endl;
        } else {
            std::cout << "Недостаточно средств." << std::endl;
        }
    }
}

void Automata::check() {
    if (state == CHECK) {
        state = COOK;
        std::cout << "Средств достаточно, начинаем приготовление напитка..." << std::endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        state = WAIT;
        std::cout << "Операция отменена. Ваши деньги возвращены." << std::endl;
    }
}

void Automata::cook() {
    if (state == COOK) {
        // Имитация процесса приготовления
        state = WAIT;
        cash = 0; // Предполагается, что стоимость напитка равна внесенной сумме
        std::cout << "Ваш напиток готов." << std::endl;
    }
}

void Automata::finish() {
    state = WAIT;
    std::cout << "Пожалуйста, заберите ваш напиток и наслаждайтесь." << std::endl;
}
