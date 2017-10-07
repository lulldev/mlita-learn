#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

int GetPositionOfMinimalNumber(vector<int> &vectorOfNumbers)
{
    set<int> existNumbers;
    int i = 0;
    int minNumberPos = i;
    while (i < vectorOfNumbers.size() - 1)
    {
        if (vectorOfNumbers[i] <= vectorOfNumbers[i + 1])
        {
            if (existNumbers.count(vectorOfNumbers[i]) == 0)
            {
                existNumbers.insert(vectorOfNumbers[i]);
                minNumberPos = i;
            }
        }
        else
        {
            if (existNumbers.count(vectorOfNumbers[i + 1]) == 0)
            {
                existNumbers.insert(vectorOfNumbers[i + 1]);
                minNumberPos = i + 1;
            }
        }
        i++;
    }
    return (minNumberPos + 1);
}

const vector<int> SplitToIntegers(string &targetString)
{
    vector<int> resultVector;
    for (int i = 0; i < strlen(targetString.c_str()); i++)
    {
        resultVector.push_back(stoi(string(1, targetString[i])));
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
            vectorOfNums = SplitToIntegers(fileLine);
        }
        else
        {
            break;
        }
        strCounter++;
    }

    cout << GetPositionOfMinimalNumber(vectorOfNums) << endl;
    return 0;
}
