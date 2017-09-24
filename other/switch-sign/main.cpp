#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

int numToPositive(int num, bool &issetNegative)
{
    if (num < 0) 
    {   
        issetNegative = true;
        return num * -1;
    }
    return num;
}

const vector<int> SplitToPositiveIntegers(const string &targetString, const char &delimiter, bool &issetNegative)
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
            resultVector.push_back(numToPositive(stoi(tmpString), issetNegative));
            tmpString = "";
        }
    }

    if (tmpString != "")
    {
        resultVector.push_back(numToPositive(stoi(tmpString), issetNegative));
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
    bool issetNegative = false;

    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            numCount = stoi(fileLine);
        }
        else if (strCounter == 1)
        {
            vectorOfNums = SplitToPositiveIntegers(fileLine, ' ', issetNegative);
        }
        else
        {
            break;
        }
        strCounter++;
    }

    int minimalSum = accumulate(vectorOfNums.begin(), vectorOfNums.end(), 0);
    
    if (issetNegative) 
    {
        minimalSum *= -1;
    }

    outputFile << minimalSum;
    return 0;
}