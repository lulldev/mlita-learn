#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

bool IsSegmentsHasOveralPoint(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22)
{

    double common = (x12 - x11) * (y22 - y21) - (y12 - y11) * (x22 - x21);

    if (common == 0)
    {
        return false;
    }

    double rH = (y11 - y21) * (x22 - x21) - (x11 - x21) * (y22 - y21);
    double sH = (y11 - y21) * (x12 - x11) - (x11 - x21) * (y12 - y11);

    double r = rH / common;
    double s = sH / common;

    if (r >= 0 && r <= 1 && s >= 0 && s <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    int fX1, fY1, fX2, fY2;
    int sX1, sY1, sX2, sY2;

    while (getline(inputFile, fileLine))
    {
        vectorOfNums = SplitToIntegers(fileLine, ' ');
        switch (strCounter)
        {
        case 0:
            fX1 = vectorOfNums[0];
            fY1 = vectorOfNums[1];
            break;
        case 1:
            fX2 = vectorOfNums[0];
            fY2 = vectorOfNums[1];
            break;
        case 2:
            sX1 = vectorOfNums[0];
            sY1 = vectorOfNums[1];
            break;
        case 3:
            sX2 = vectorOfNums[0];
            sY2 = vectorOfNums[1];
            break;
        default:
            break;
            break;
        }
        strCounter++;
    }

    string result = IsSegmentsHasOveralPoint(fX1, fY1, fX2, fY2, sX1, sY1, sX2, sY2) ? "Yes" : "No";

    outputFile << result;

    return 0;
}
