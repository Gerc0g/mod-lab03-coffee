// Copyright 2022 UNN-IASR
// Automata.h
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <vector>
#include <string>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
    SERVE
};

class Automata {
     private:
        int cash;
        std::vector<std::string> menu;
        std::vector<int> prices;
        STATES state;

     public:
        Automata();

        void on();
        void off();
        void coin(int amount);
        std::vector<std::string> getMenu() const;
        STATES getState() const;
        void choice(int drink);
        bool check(int drink);
        void cancel();
        void cook(int drink);
        void finish();
};
#endif  // INCLUDE_AUTOMATA_H_

