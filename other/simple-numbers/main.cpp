#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

double GetSumBetweenSimpleNumbers(int a, int b) 
{
    return (b * (b - a)) / 2);
}

const vector<int> SplitToIntegers(const string &targetString, const char &delimiter)
{
    string tmpString("");
    vector<int> resultVector;

    for (auto prepareString : targetString)
    {
        if (prepareString != delimiter)
        {
            tmpString += prepareString;
        }
        else if (prepareString == delimiter && tmpString != "")
        {
            resultVector.push_back(stoi(tmpString));
            tmpString = "";
        }
    }

    if (tmpString != "")
    {
        resultVector.push_back(stoi(tmpString));
    }
    return resultVector;
}

int main()
{
    ifstream inputFile(INPUT_FILENAME);
    ofstream outputFile(OUTPUT_FILENAME);

    if ((!inputFile.is_open() || inputFile.fail()) || (!outputFile.is_open() || outputFile.fail()))
    {
        cout << "Error i/o opening files" << endl;
        return 1;
    }

    string fileLine;
    vector<int> vectorOfNums;
    int a;
    int b;

    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            vectorOfNums = SplitToIntegers(fileLine, ' ');
            a = vectorOfNums[0];
            b = vectorOfNums[1];
        }
        else
        {
            break;
        }
        strCounter++;
    }

    outputFile << GetSumBetweenSimpleNumbers(a, b);
    return 0;
}