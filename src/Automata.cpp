#include "Automata.h"
#include <iostream>

Automata::Automata() : state(OFF), cash(0) {
    // Предполагаемое заполнение меню и цен
    menu = {"Tea", "Coffee", "Milk"};
    prices = {25, 50, 30};
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Автомат включен." << std::endl;
    }
}

void Automata::off() {
    if (state != OFF) {
        state = OFF;
        std::cout << "Автомат отключен." << std::endl;
    }
}

void Automata::coin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        if (amount > 0) { // Проверка на положительную сумму монеты
            cash += amount;
            state = ACCEPT;
            std::cout << "Вы положили  " << amount << " coins." << std::endl;
        } else {
            std::cout << "Недопустимая сумма монеты." << std::endl;
        }
    }
}

std::vector<std::string> Automata::getMenu() const {
    return menu;
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(int drink) {
    if (state == ACCEPT && drink >= 0 && drink < menu.size()) {
        if (check(drink)) {
            cook(drink);
        } else {
            std::cout << "Не хватает денег." << std::endl;
            cancel();
        }
    }
}

bool Automata::check(int drink) {
    return cash >= prices[drink];
}

void Automata::cancel() {
    if (state == ACCEPT) {
        std::cout << "Транзакция отменена. Возвращаем " << cash << " coins." << std::endl;
        cash = 0;
        state = WAIT;
    }
}

void Automata::cook(int drink) {
    if (state == ACCEPT) {
        std::cout << "Напиток готовиться " << menu[drink] << "." << std::endl;
        cash -= prices[drink];
        state = COOK;
        finish();
    }
}

void Automata::finish() {
    std::cout << "Напиток готов!" << std::endl;
    state = SERVE;
    off();
}
