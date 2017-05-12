#include <iostream>
#include <vector>
#include <fstream>

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

int main(int argc, const char * argv[])
{
    if (argc != 2)
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
    int elementsCount = 0;
    vector<int> arrayElements;

    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            elementsCount = stoi(fileLine);
        }
        else
        {
            arrayElements = SplitIntegers(fileLine, ' ');
        }
        strCounter++;
    }
    cout << arrayElements[1] << endl;
    return 0;
}