#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <list>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    (void)other;
    return *this;
}

RPN::~RPN() {}

bool RPN::evaluate(const std::string& expression) const {
    std::stack<int, std::list<int> > stack;
    std::stringstream ss(expression);
    std::string token;

    if (expression.empty()) {
        std::cerr << "Error" << std::endl;
        return false;
    }

    while (ss >> token) {
        if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
            if (stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return false;
            }
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (token == "+") stack.push(operand1 + operand2);
            else if (token == "-") stack.push(operand1 - operand2);
            else if (token == "*") stack.push(operand1 * operand2);
            else if (token == "/") {
                if (operand2 == 0) {
                    std::cerr << "Error" << std::endl;
                    return false;
                }
                stack.push(operand1 / operand2);
            }
        } else if (token.length() == 1 && isdigit(token[0])) {
            stack.push(token[0] - '0');
        } else {
            // Numbers must be < 10, thus length 1 (since positive single digits)
            std::cerr << "Error" << std::endl;
            return false;
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return false;
    }

    std::cout << stack.top() << std::endl;
    return true;
}
