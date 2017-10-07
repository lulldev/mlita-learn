#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

int GetMinimalSumByReplacement(vector<int> &vectorOfNums, int replaceCount) 
{
    sort(vectorOfNums.begin(), vectorOfNums.end(), [](const int a, const int b) { return a > b; });
    int i = 0;
    while (i < vectorOfNums.size()) 
    {
        vectorOfNums[i] = vectorOfNums[i] * (-1);
        replaceCount--;
        if (replaceCount == 0) {
            break;
        }
        i++;
    }
    return accumulate(vectorOfNums.begin(), vectorOfNums.end(), 0);
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
    int numberLength = 0;
    int strCounter = 0;
    vector<int> vectorOfNums;

    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            numberLength = stoi(fileLine);
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
    cout << numberLength << endl;
    // outputFile << GetMinimalSumByReplacement(vectorOfNums, replaceCount);
    return 0;
}