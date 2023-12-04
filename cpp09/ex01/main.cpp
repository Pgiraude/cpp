#include "RPN.hpp"

int main(int argc, char **argv)
{

    std::stack<int> stack;

    if (argc != 2)
        return (1);
    
    std::stringstream ss(argv[1]);
    std::string token;

    while (ss >> token)
    {
        std::cout << token << std::endl;
        if (token == "-" || token == "+" || token == "/" || token == "*")
        {
            if (stack.size() < 2)
                return (4);
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();

            switch (token[0])
            {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                default:
                    return (100);
                    break;
            }
            
        }
        else
        {
            std::size_t i = 0;
            if (!token.empty() && token[i] == '-')
                i++;
            while (i != token.size())
            {
                if (!std::isdigit(token[i]))
                    return (3);
                i++;
            }
                
            int value;
            std::stringstream convert;
            convert << token;
            convert >> value;
            convert.clear();

            stack.push(value);
        }
    }
    if (stack.size() != 1)
        return (200);
    std::cout << "result: " << stack.top() << std::endl;
    return (0);
}