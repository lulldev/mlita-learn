#include "BracketHandler.h"

using namespace std;

string ConcatExpressions(const string bracketExpression1, const string bracketExpression2,
                         const string resultString = T_brackets_expression())
{
    return bracketExpression1 + bracketExpression2 + resultString;
}

set<string> GenerateBracketExpression(int length)
{
    set<string> from;
    set<string> to;
    to.insert("");

    for(int i = 0; i < length / 2; ++i)
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

void OutputResultBracketExpression(set<string> bracketExpression, ostream& output)
{
    for(set<string>::const_iterator  it = bracketExpression.begin(); it != bracketExpression.end(); ++it)
    {
        output << *it << endl;
    }
}