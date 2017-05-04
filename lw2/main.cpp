#include <iostream>
#include <vector>
#include <fstream>

#include "TriangleSum/TriangleSum.h"

using namespace std;

int main(int argc, const char * argv[])
{
    if (argc != 3)
    {
        cout << "Program arguments startup error\n" << "Usage: program <input file> <output file>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cout << "Error i/o files: " << argv[1] << endl;
        return 1;
    }

    if (inputFile.fail() || !outputFile.is_open())
    {
        cout << "Fail i/o files" << endl;
        return 1;
    }

    string fileLine;
    int strCounter = 0;
    int triangleWeight = 0;

    vector<vector<int>> vectorOfTriangleData;

    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            triangleWeight = stoi(fileLine);
        }
        else
        {
            vector<int> stringToSplitVector = SplitIntegers(fileLine, ' ');
            vectorOfTriangleData.push_back(stringToSplitVector);
        }
        strCounter++;
    }

    CalculateTriangleMaxSum(triangleWeight, vectorOfTriangleData, outputFile);

    return 0;
}