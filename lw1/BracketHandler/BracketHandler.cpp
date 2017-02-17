#include <iostream>
#include <stack>

#include "BracketHandler.h"

using namespace std;

void GenerateSequence(size_t n, size_t openCounter, size_t closeCounter, string resultString)
{
    if (openCounter + closeCounter == n && IsBracketsValidInString(resultString))
    {
        cout << resultString << endl;
        return;
    }

    if (openCounter < n)
    {
        GenerateSequence(n, openCounter + 1, closeCounter, resultString + '(');
    }

    if (openCounter > closeCounter)
    {
        GenerateSequence(n, openCounter, closeCounter + 1, resultString + ')');
    }
}


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