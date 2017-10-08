#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

bool IsSegmentsHasOveralPoint(int fX1, int fY1, int fX2, int fY2, int sX1, int sY1, int sX2, int sY2)
{
    int a = fX2 - fX1,
        b = sX1 - sX2,
        c = sX1 - fX1,
        d = fY2 - fY1,
        e = sY1 - sY2,
        f = sY1 - fY1;

    double determinant = (a * e) - (b * d);
    if (determinant == 0)
    {
        return false;
    }
    else
    {
        double dt = c * e - f * b;
        double ds = a * f - c * d;
        double t = dt / determinant;
        double s = ds / determinant;
        if ((s >= 0 and s <= 1) && (0 <= t) and (t <= 1))
        {
            return true;
        }
    }

    return false;
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