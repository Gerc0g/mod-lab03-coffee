// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>

int main() {
    Automata coffeeMachine;

    coffeeMachine.on();
    coffeeMachine.coin(50);
    auto menu = coffeeMachine.getMenu();
    std::cout << "Доступные напитки:" << std::endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << ". " << menu[i] << std::endl;
    }
    coffeeMachine.choice(1);
    coffeeMachine.check();
    coffeeMachine.cook();
    coffeeMachine.finish();

    // отмена операции
    coffeeMachine.on();
    coffeeMachine.coin(100);
    coffeeMachine.choice(2);
    coffeeMachine.cancel();

    // поведение при недостаточной сумме
    coffeeMachine.on();
    coffeeMachine.coin(10);
    coffeeMachine.choice(1);
    coffeeMachine.check();

    // Выключение автомата
    coffeeMachine.off();

    return 0;
}