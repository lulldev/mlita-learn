#include <iostream>
#include <stack>

#include "BracketHandler.h"

using namespace std;

bool IsBracketsValidInString(std::string preparedString)
{
    std::stack<char> charStack;
    for(int i = 0; i < preparedString.length(); ++i)
    {
        if ((preparedString[i] =='(') || (preparedString[i] =='['))
        {
            charStack.push(preparedString[i]);
        }
        else
        {
            if (charStack.size() == 0)
            {
                return false;
            }

            char currentChar = charStack.top(); // берем последнюю открывающую скобку
            charStack.pop();

            if ((currentChar == '(' && preparedString[i] != ')') ||
                (currentChar == '[' && preparedString[i] != ']'))
            {
                return false;
            }

        }
    }
    return (charStack.size() == 0);
}

void BracketHandler()
{

}