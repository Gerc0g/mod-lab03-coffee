// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

// Тестирование включения и выключения автомата
TEST(AutomataTest, TurnOnOff) {
    Automata automata;
    ASSERT_EQ(automata.getState(), OFF);
    automata.on();
    EXPECT_EQ(automata.getState(), WAIT);
    automata.off();
    EXPECT_EQ(automata.getState(), OFF);
}

// Тестирование добавления монет
TEST(AutomataTest, InsertCoins) {
    Automata automata;
    automata.on();
    automata.coin(50);
    EXPECT_EQ(automata.getState(), ACCEPT);
    EXPECT_EQ(automata.getState(), ACCEPT);
    automata.coin(100);
    EXPECT_EQ(automata.getState(), ACCEPT);
}

// Тестирование выбора напитка
TEST(AutomataTest, MakeSelection) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(0); // Предположим, что это чай
    EXPECT_EQ(automata.getState(), SERVE);
}

// Тестирование отмены операции
TEST(AutomataTest, CancelTransaction) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.cancel();
    EXPECT_EQ(automata.getState(), WAIT);
}

// Тестирование проверки достаточности средств для выбора напитка
TEST(AutomataTest, CheckSufficientFunds) {
    Automata automata;
    automata.on();
    automata.coin(20);
    EXPECT_FALSE(automata.check(0));
    automata.coin(30);
    EXPECT_TRUE(automata.check(0)); // Теперь должно быть достаточно средств
}

// Тестирование приготовления напитка
TEST(AutomataTest, MakeDrink) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(1); // Предполагаем, что это кофе
    EXPECT_EQ(automata.getState(), SERVE);
}

// Тестирование получения меню
TEST(AutomataTest, GetMenu) {
    Automata automata;
    auto menu = automata.getMenu();
    EXPECT_EQ(menu.size(), 3); // Предполагаем, что в меню три напитка
}

// Тестирование состояния автомата после выключения
TEST(AutomataTest, StateAfterTurningOff) {
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(automata.getState(), OFF);
}

// Тестирование добавления недопустимого количества монет
TEST(AutomataTest, InsertInvalidCoins) {
    Automata automata;
    automata.on();
    automata.coin(-10);
    EXPECT_EQ(automata.getState(), WAIT);
}
