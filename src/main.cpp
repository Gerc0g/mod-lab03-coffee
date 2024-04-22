// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>

int main() {
    Automata automata;
    automata.on();
    automata.coin(100); // Пользователь вносит 100 монет
    std::vector<std::string> menu = automata.getMenu();

    std::cout << "Выберите напиток:" << std::endl;
    for (int i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << ". " << menu[i] << std::endl;
    }

    automata.choice(1); // Пользователь выбирает кофе (индекс 1)
    automata.off();
    return 0;
}
