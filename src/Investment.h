#pragma once
#include <string>
#include <vector>

class BankAccount;

class Investment {
public:
    double capital;
    double growth_rate;
    std::string name;

    static std::vector<Investment*> allInvestments;

    Investment(double new_capital, double new_growth_rate, const std::string& new_name);

    double update_value();
    std::string get_name() const;

    static Investment* getInvestmentByName(const std::string& name);
    static void buyInvestment(Investment* investment, BankAccount& account);
};
