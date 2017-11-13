#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

size_t GetPrimeSumBetweenNumbers(size_t a, size_t b)
{
    size_t n = b;
    size_t sum = 0;
    vector<size_t> prime(n, true);

    for (int i = 0; i < n; i++)
    {
        prime[i] = i;
    }

    for (int i = 2; i < (n + 1); i++)
    {
        if (prime[i] != 0)
        {
            sum += prime[i];
            for (int j = (i * i); j < (n + 1); j += i)
            {
                prime[j] = 0;
            }
        }
    }
    return sum;
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
    int strCounter = 0;
    vector<int> vectorOfNums;
    size_t a;
    size_t b;

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

    outputFile << GetPrimeSumBetweenNumbers(a, b);
    return 0;
}