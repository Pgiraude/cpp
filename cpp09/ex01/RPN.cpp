#include "RPN.hpp"


RPN::RPN(void)
{
    //std::cout << "RPN VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

RPN::RPN(RPN const &copy)
{
    (void)copy;
    //std::cout << "RPN COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

RPN::~RPN(void)
{
    //std::cout << "RPN VOID " << RED "destructor" RESET << " called" << std::endl;
}

RPN    &RPN::operator=(RPN const &rhs)
{
    (void)rhs;
    //std::cout << "RPN '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

static int  push_value(std::string &token, std::stack<int> &stack)
{
    std::size_t i = 0;
    if (!token.empty() && token[i] == '-')
        i++;
    while (i != token.size())
    {
        if (!std::isdigit(token[i]))
            throw RPN::NotDigit();
        i++;
    }
    int value;
    std::stringstream convert;
    convert << token;
    convert >> value;
    convert.clear();
    if (value == std::numeric_limits<int>::max()
        || value == std::numeric_limits<int>::min())
        throw RPN::limits();
    stack.push(value);
    return (0);
}

static int  operations(std::string &token, std::stack<int> &stack)
{
    if (stack.size() < 2)
        throw RPN::Error();
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    switch (token[0])
    {
        case '+':
            stack.push(b + a);
            break;
        case '-':
            stack.push(b - a);
            break;
        case '*':
            stack.push(b * a);
            break;
        case '/':
            stack.push(b / a);
            break;
        default:
            throw RPN::Error();
            break;
    }
    if (stack.top() == std::numeric_limits<int>::max()
        || stack.top() == std::numeric_limits<int>::min())
        throw RPN::limits();
    return (0);
}

void    RPN::processing(char *input)
{
    std::stack<int> stack;
    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (token == "-" || token == "+" || token == "/" || token == "*")
            operations(token, stack);
        else
            push_value(token, stack);
    }
    ss.clear();
    if (stack.size() != 1)
        throw RPN::Error();
    if (stack.top() == std::numeric_limits<int>::max()
        || stack.top() == std::numeric_limits<int>::min())
        throw RPN::limits();
    std::cout << GREEN "Result: " RESET << stack.top() << std::endl;
}