#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

struct greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int GetMinimalSumByReplacement(const vector<int> &vectorOfNums, int replaceCount) 
{
    sort(vectorOfNums.begin(), vectorOfNums.end(), greater());
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
    int numCount = 0;
    int replaceCount = 0;
    int strCounter = 0;
    vector<int> vectorOfNums;

    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            vectorOfNums = SplitToIntegers(fileLine, ' ');
            numCount = vectorOfNums[0];
            replaceCount = vectorOfNums[1];
        }
        else if (strCounter == 1)
        {
            vectorOfNums = SplitToIntegers(fileLine, ' ');
        }
        else
        {
            break;
        }
        strCounter++;
    }

    int minimalSum = accumulate(vectorOfNums.begin(), vectorOfNums.end(), 0);
    outputFile << minimalSum;
    return 0;
}