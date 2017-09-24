#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

int numToPositive(int num)
{
    return (num < 0) ? num * -1 : num;
}

const vector<int> SplitToPositiveIntegers(const string &targetString, const char &delimiter)
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
            resultVector.push_back(numToPositive(stoi(tmpString)));
            tmpString = "";
        }
    }

    if (tmpString != "")
    {
        resultVector.push_back(numToPositive(stoi(tmpString)));
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
    int numCount = 0;
    int strCounter = 0;
    vector<int> vectorOfNums;

    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            numCount = stoi(fileLine);
        }
        else if (strCounter == 1)
        {
            vectorOfNums = SplitToPositiveIntegers(fileLine, ' ');
        }
        else
        {
            break;
        }
        strCounter++;
    }

    cout << accumulate(vectorOfNums.begin(), vectorOfNums.end(), 0) << endl;
    return 0;
}