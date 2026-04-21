#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> _db;
    bool isValidDate(const std::string& date) const;
    bool loadDatabase(const std::string& filename);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void evaluateFile(const std::string& filename);
    std::string trim(const std::string& str) const;
};

#endif
