#include <iostream>
#include <set>
#include <sstream>

typedef std::string T_brackets_expression;

std::string ConcatExpressions(const std::string bracketExpression1, const std::string bracketExpression2,
                         const std::string resultString);

std::set<std::string> GenerateBracketExpression(int length);
void OutputResultBracketExpression(std::set<std::string> bracketExpression, std::ostream& output);
