#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const string inputFileName = "input.txt";
const string outputFileName = "output.txt";

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

void FindStepPattern (int n, int k, int& pStep, int& pCount)
{
//    int i = 1;
//    while (i <= n)
//    {
//
//    }
}

int main(int argc, const char * argv[])
{

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (inputFile.fail() || outputFile.fail())
    {
        cout << "Error i/o files" << endl;
        return 1;
    }

    vector<int> startedValues;
    vector<int> targetRooms;
    string fileLine;
    size_t strCounter = 0;
    size_t targetRoomsCount = 0; // q - количество комнат для которых определить этажи

    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            startedValues = SplitIntegers(fileLine, ' ');
        }
        else if (strCounter == 1)
        {
            targetRoomsCount = stoi(fileLine);
        }
        else if (strCounter == 2)
        {
            targetRooms = SplitIntegers(fileLine, ' ');
        }
        strCounter++;
    }

    int n = startedValues[0];
    int k = startedValues[1];
    int x = startedValues[2];
    int y = startedValues[3];

    cout << "Startup values:" << endl;
    cout << "q = " << to_string(targetRoomsCount) << endl;
    cout << "n = " << to_string(n) << endl;
    cout << "k = " << to_string(k) << endl;
    cout << "x = " << to_string(x) << endl;
    cout << "y = " << to_string(y) << endl;

    int pStep = 1;
    int pCount = 0;
    FindStepPattern (n, k, pStep, pCount);
    

    return 0;
}