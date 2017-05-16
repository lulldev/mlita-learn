#include "TriangleSum.h"

using namespace std;

const vector<int> SplitIntegers(const string& targetString, const char& delimiter)
{
    string tmpString("");
    vector<int> resultVector;

    for(auto prepareString : targetString)
    {
        if(prepareString != delimiter)
        {
            tmpString += prepareString;
        }
        else if(prepareString == delimiter && tmpString != "")
        {
            resultVector.push_back(stoi(tmpString));
            tmpString = "";
        }
    }

    if(tmpString != "")
    {
        resultVector.push_back(stoi(tmpString));
    }

    return resultVector;
}

void CalculateTriangleMaxSum(int triangleWeight, std::vector<std::vector<int>>& vectorOfTriangleData,
                             std::ofstream& outputFile)
{
    //int triangleLevelCounter = triangleWeight - 1;
    //std::map <string, string> resultWayAsMaxSum; // example {"way": "sum"}

    std::vector<std::vector<int>> vectorOfRelativeSums;
    triangleWeight = triangleWeight - 1;

    bool isProcessed = false;
    while (!isProcessed)
    {
        int currentLineCounter = triangleWeight - 1;
        while (currentLineCounter >= 0) // цикл по строке m - n
        {
            int currentPosition = 0;
            while (currentPosition <= currentLineCounter)
            {
                cout << vectorOfTriangleData[currentLineCounter][currentPosition] << endl;
                cout << "Daughters:" << endl;
                cout << vectorOfTriangleData[currentLineCounter + 1][currentPosition] << endl;
                cout << vectorOfTriangleData[currentLineCounter + 1][currentPosition + 1] << endl;
                cout << endl;
                currentPosition++;
            }
            currentLineCounter--;
        }

        isProcessed = true;
    }

//    for (auto itResultMap = resultWayAsMaxSum.begin(); itResultMap != resultWayAsMaxSum.end(); ++itResultMap)
//    {
//        cout << itResultMap->first << " : " << itResultMap->second << "\t\t   " << endl;
//    }


}