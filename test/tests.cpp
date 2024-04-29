// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public ::testing::Test {
 protected:
    Automata automata;

    void SetUp() override {
    automata.on();
}

};

TEST_F(AutomataTest, IsInitiallyOff) {
    Automata newAutomata;
    EXPECT_EQ(OFF, newAutomata.getState());
}

TEST_F(AutomataTest, TurnsOn) {
    EXPECT_EQ(WAIT, automata.getState());
}

TEST_F(AutomataTest, TurnsOff) {
    automata.off();
    EXPECT_EQ(OFF, automata.getState());
}

TEST_F(AutomataTest, AcceptsCoins) {
    automata.coin(50);
    EXPECT_EQ(ACCEPT, automata.getState());
}

TEST_F(AutomataTest, RefundsCoins) {
    automata.coin(50);
    automata.cancel();
    EXPECT_EQ(WAIT, automata.getState());
}

TEST_F(AutomataTest, CanMakeSelection) {
    automata.coin(50);
    automata.choice(1);
    EXPECT_EQ(CHECK, automata.getState());
}

TEST_F(AutomataTest, RejectsInvalidSelection) {
    automata.coin(50);
    automata.choice(10);
    EXPECT_NE(CHECK, automata.getState());
}

TEST_F(AutomataTest, ChecksWithInsufficientFunds) {
    automata.coin(10);
    automata.choice(0);
    EXPECT_NE(COOK, automata.getState());
}

TEST_F(AutomataTest, CooksWhenFundsAreSufficient) {
    automata.coin(50);
    automata.choice(1);
    automata.check();
    EXPECT_EQ(COOK, automata.getState());
}

TEST_F(AutomataTest, CompletesSessionAfterCooking) {
    automata.coin(50);
    automata.choice(1);
    automata.check();
    automata.cook();
    automata.finish();
    EXPECT_EQ(WAIT, automata.getState());
}

TEST_F(AutomataTest, MenuReturnsCorrectly) {
    auto menu = automata.getMenu();
    ASSERT_EQ(3, menu.size());
}
