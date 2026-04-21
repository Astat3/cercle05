#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->_db = other._db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t");
    if (std::string::npos == first) return str;
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    int year, month, day;
    std::stringstream ss(date);
    char dash1, dash2;
    if (!(ss >> year >> dash1 >> month >> dash2 >> day)) return false;
    if (dash1 != '-' || dash2 != '-') return false;
    
    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) return false;
    
    // Leap year checks and month specific max days
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[2] = 29;
    }
    
    if (day > daysInMonth[month]) return false;
    
    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file " << filename << std::endl;
        return false;
    }
    
    std::string line;
    std::getline(file, line); // parse header
    
    while (std::getline(file, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos) continue;
        
        std::string dateStr = trim(line.substr(0, pos));
        std::string rateStr = trim(line.substr(pos + 1));
        
        std::stringstream ss(rateStr);
        double rate;
        if (ss >> rate) {
            _db[dateStr] = rate;
        }
    }
    return true;
}

void BitcoinExchange::evaluateFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header usually "date | value"
    
    while (std::getline(file, line)) {
        size_t pos = line.find('|');
        if (pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string dateStr = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));
        
        if (!isValidDate(dateStr)) {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        double value;
        std::string trailing;
        std::stringstream ss(valueStr);
        if (!(ss >> value) || (ss >> trailing)) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::map<std::string, double>::iterator it = _db.upper_bound(dateStr);
        if (it == _db.begin()) {
            std::cerr << "Error: no valid older date in database." << std::endl;
            continue;
        }
        --it; // Find the highest date that is <= target date
        
        double result = value * it->second;
        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
}
