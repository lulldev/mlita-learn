#include "BracketHandler.h"

using namespace std;

void ValidBracketsGenerator(ostream& output, int amount, std::string& brackets, std::string& check, int counter)
{
    if ((counter == amount / 2) && (check.empty()))
    {
        output << brackets << endl;
    }

    if (counter < amount / 2)
    {
        string charStack = brackets + '(';
        string s2 = check + ')';
        string s3 = brackets + '[';
        string s4 = check + ']';

        ValidBracketsGenerator(output, amount, charStack, s2, counter + 1);
        ValidBracketsGenerator(output, amount, s3, s4, counter + 1);
    }

    if (!check.empty())
    {
        string charStack;
        (check.back() == ')') ?
                charStack = brackets + ')' : charStack = brackets + ']';
        string s2 = check.substr(0, check.size() - 1);
        ValidBracketsGenerator(output, amount, charStack, s2, counter);
    }
}

bool IsBracketsValid(string bracketsStr)
{
    int i = 0;
    int flag = 0;
    stack<char> charStack;
    while (bracketsStr[i] != '\0')
    {
        if(bracketsStr[i]=='(')
        {
            charStack.push(')');
        }
        else if (bracketsStr[i]=='{')
        {
            charStack.push('}');
        }
        else if(bracketsStr[i]=='[')
        {
            charStack.push(']');
        }
        else if(charStack.empty() || charStack.top() != bracketsStr[i])
        {
            return false;
        }
        else
        {
            charStack.pop();
        }
        i++;
    }
    return charStack.empty();
}