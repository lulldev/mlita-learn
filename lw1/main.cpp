#include <algorithm>
#include <iostream>
#include <set>

#include "BracketHandler/BracketHandler.h"

using namespace std;

typedef string T_brackets_expression;

string ConcatExpressions(const string bracketExpression1, const string bracketExpression2,
                              const string resultString = T_brackets_expression())
{
    return bracketExpression1 + bracketExpression2 + resultString;
}

set<string> make_brackets_expressions(int  len)
{
    set<string>  from;
    set<string>  to;
    to.insert("");
    for(int  L = 0; L < len / 2; ++L)
    {
        swap(from, to);
        to.clear();
        for(set<string>::const_iterator it = from.begin(); it != from.end(); ++it)
        {
            to.insert(ConcatExpressions("(", *it, ")") );
            to.insert(ConcatExpressions("[", *it, "]") );

            to.insert(ConcatExpressions("()", *it) );
            to.insert(ConcatExpressions(*it, "()") );

            to.insert(ConcatExpressions("[]", *it) );
            to.insert(ConcatExpressions(*it, "[]") );
        }
    }
    return  to;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    size_t len;
    cin >> len;

    set<string> brackets_expressions = make_brackets_expressions(len);

    for(set<string>::const_iterator  it = brackets_expressions.begin(); it != brackets_expressions.end(); ++it)
    {
        cout << *it << endl;
    }
}