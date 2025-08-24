#include "Investment.h"
#include "BankAccount.h"
#include <random>
#include <iostream>

std::vector<Investment*> Investment::allInvestments;

Investment::Investment(double new_capital, double new_growth_rate, const char* new_name)
    : capital(new_capital), growth_rate(new_growth_rate), name(new_name)
{
    allInvestments.push_back(this);
}

double Investment::update_value() {
    double max = capital * (growth_rate / 100);
    double min = -max;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(min, max);

    capital += dist(gen);
    return capital;
}

std::string Investment::get_name() const {
    return name;
}

Investment* Investment::getInvestmentByName(const std::string& name) {
    for (Investment* inv : allInvestments) {
        if (inv->get_name() == name) return inv;
    }
    return nullptr;
}

void Investment::buyInvestment(Investment* investment, BankAccount& account) {
    if (account.get_balance() >= investment->capital) {
        account.withdraw(investment->capital);
        std::cout << "Bought investment: " << investment->get_name()
            << " for $" << investment->capital << std::endl;
    }
    else {
        std::cout << "Not enough funds to buy: " << investment->get_name() << std::endl;
    }
}
