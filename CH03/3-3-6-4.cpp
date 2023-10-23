#include <iostream>
#include <stack>
#include <string>

int getPriority(char op)
{
    switch (op) {
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

int compute(int a, int b, char op)
{
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b ? a / b : 0; // 防止除以0
    default:
        return 0;
    }
}

int evaluateExpression(const std::string &exp)
{
    std::stack<int> nums;
    std::stack<char> ops;

    for (size_t i = 0; i < exp.length(); ++i) {
        if (isdigit(exp[i])) {
            nums.push(exp[i] - '0');
        }
        else if (exp[i] == '(') {
            ops.push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (ops.top() != '(') {
                char op = ops.top();
                ops.pop();
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(compute(a, b, op));
            }
            ops.pop(); // 弹出 '('
        }
        else { // 只有当栈顶的操作符优先级大于等于当前操作符时才进行计算
            while (!ops.empty() && getPriority(ops.top()) >= getPriority(exp[i])) {
                char op = ops.top();
                ops.pop();
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(compute(a, b, op));
            }
            ops.push(exp[i]);
        }
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        nums.push(compute(a, b, op));
    }

    return nums.top();
}

int main()
{
    std::string expression;
    std::cout << "请输入表达式: ";
    std::cin >> expression;
    std::cout << "计算结果是: " << evaluateExpression(expression) << std::endl;
    return 0;
}
