#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int getPriority(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

std::string infixToPostfix(const std::string& exp) {
    std::stack<char> operatorStack;
    std::string postfix = "";
    
    for (char ch : exp) {
        if (isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operatorStack.push(ch);
        } else if (ch == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty()) operatorStack.pop(); // Pop '('
        } else {
            while (!operatorStack.empty() && getPriority(ch) <= getPriority(operatorStack.top())) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string exp;
    std::cout << "Enter infix expression: ";
    std::cin >> exp;
    std::cout << "Postfix expression: " << infixToPostfix(exp) << std::endl;
    return 0;
}
