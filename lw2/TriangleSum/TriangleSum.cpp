#include "TriangleSum.h"

using namespace std;

#define INFINITIVE 100000

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

    std::vector<std::vector<int>> vectorOfRelativeSums = vectorOfTriangleData;
    triangleWeight = triangleWeight - 1;

    int currentLineCounter = triangleWeight - 1;
    while (currentLineCounter >= 0) // цикл по строке
    {
        int currentPosition = 0;
        while (currentPosition <= currentLineCounter)
        {
            vectorOfRelativeSums[currentLineCounter][currentPosition] = INFINITIVE;
            currentPosition++;
        }
        currentLineCounter--;
    }

    currentLineCounter = triangleWeight - 1;
    while (currentLineCounter >= 0) // цикл по строке
    {
        int currentPosition = 0;
        while (currentPosition <= currentLineCounter)
        {
            int currentPoint = vectorOfTriangleData[currentLineCounter][currentPosition];
            int leftChildPoint = vectorOfTriangleData[currentLineCounter + 1][currentPosition];
            int rightChildPoint = vectorOfTriangleData[currentLineCounter + 1][currentPosition + 1];

//            cout << currentPoint << " - " << leftChildPoint << ":" << rightChildPoint << endl;

            // кладем суммы.
            if (vectorOfRelativeSums[currentLineCounter + 1][currentPosition] == INFINITIVE)
            {
                // кладем в левую дочернюю если там бесокнечность
                vectorOfRelativeSums[currentLineCounter + 1][currentPosition] = currentPoint + leftChildPoint;
            }
            else
            {
                // если текущая больше дочерней - кладем текущее
                if ((currentPoint + leftChildPoint) > vectorOfRelativeSums[currentLineCounter + 1][currentPosition])
                {
                    vectorOfRelativeSums[currentLineCounter + 1][currentPosition] = currentPoint + leftChildPoint;
                }
            }

            // так же для правой
            if (vectorOfRelativeSums[currentLineCounter + 1][currentPosition + 1] == INFINITIVE)
            {
                // кладем в правую дочернюю если там бесокнечность
                vectorOfRelativeSums[currentLineCounter + 1][currentPosition + 1] = currentPoint + rightChildPoint;
            }
            else
            {
                // если текущая больше дочерней - кладем текущее
                if ((currentPoint + rightChildPoint) > vectorOfRelativeSums[currentLineCounter + 1][currentPosition + 1])
                {
                    vectorOfRelativeSums[currentLineCounter + 1][currentPosition + 1] = currentPoint + leftChildPoint;
                }
            }

            currentPosition++;
        }
        currentLineCounter--;
    }

    currentLineCounter = 0;
    while (currentLineCounter <= triangleWeight - 1)
    {
        int currentPosition = 0;
        while (currentPosition <= currentLineCounter)
        {
            int sumLeftChildPoint = vectorOfRelativeSums[currentLineCounter + 1][currentPosition];
            int sumRightChildPoint = vectorOfRelativeSums[currentLineCounter + 1][currentPosition + 1];
            cout << sumLeftChildPoint << ":" << sumRightChildPoint << endl;
            currentPosition++;
        }
        cout << endl;
        currentLineCounter++;
    }

//    for (auto itResultMap = resultWayAsMaxSum.begin(); itResultMap != resultWayAsMaxSum.end(); ++itResultMap)
//    {
//        cout << itResultMap->first << " : " << itResultMap->second << "\t\t   " << endl;
//    }


}