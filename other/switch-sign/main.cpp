#include <iostream>
#include <vector>
#include <fstream>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

int main()
{

    ifstream inputFile(INPUT_FILENAME);
    ofstream outputFile(OUTPUT_FILENAME);

    if ((!inputFile.is_open() || inputFile.fail()) || (!outputFile.is_open() || outputFile.fail()))
    {
        cout << "Error i/o opening files" << endl;
        return 1;
    }

    /*
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
    */
    return 0;
}