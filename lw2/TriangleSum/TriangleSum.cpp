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
    int triangleLevelCounter = triangleWeight - 1;
    std::map <string, string> resultWayAsMaxSum; // example {"way": "sum"}
    while (triangleLevelCounter >= 0)
    {
        int lineElement = 0;
        while (lineElement != vectorOfTriangleData[triangleLevelCounter].size())
        {
            int currentLineElement = vectorOfTriangleData[triangleLevelCounter][lineElement];
            if (lineElement == 0)
            {
                int lineCounter = lineElement; // == 0
                int sum = 0;
                string way("");
                while (lineCounter != (triangleWeight))
                {
                    sum += vectorOfTriangleData[lineCounter][0];
                    way += to_string(vectorOfTriangleData[lineCounter][0]);
                    lineCounter++;
                }
                resultWayAsMaxSum.insert(pair<string, string>(way, to_string(sum)));
            }
            else if (lineElement == vectorOfTriangleData[triangleLevelCounter].size() - 1)
            {
                int lineCounter = 0; // == last element in line
                int sum = 0;
                string way("");
                while (lineCounter != (triangleWeight))
                {
                    int lastLineElement = vectorOfTriangleData[lineCounter].size() - 1;
                    sum += vectorOfTriangleData[lineCounter][lastLineElement];
                    way += to_string(vectorOfTriangleData[lineCounter][lastLineElement]);
                    lineCounter++;
                }
                resultWayAsMaxSum.insert(pair<string, string>(way, to_string(sum)));
            }
            else
            {
                int upCounter = 0;
                while (lineCounter != (triangleWeight))
                {

                }
            }
            lineElement++;
        }
        triangleLevelCounter--;
    }


    for (auto itResultMap = resultWayAsMaxSum.begin(); itResultMap != resultWayAsMaxSum.end(); ++itResultMap)
    {
        cout << itResultMap->first << " : " << itResultMap->second << "\t\t   " << endl;
    }


}