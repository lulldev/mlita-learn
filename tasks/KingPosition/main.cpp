#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int GetMinWayToFinish (int kingX, int kingY)
{
    return (kingX >= kingY) ? (kingX - 1) : (kingY - 1);
}

int SpecialCheckKingPosition (int kingX, int kingY)
{
    return (kingX < kingY && kingX % 2 == 0) || (kingY < kingX && kingY % 2 == 0);
}

int KingGameImitation (int kingX, int kingY)
{
    int minWayToFinish = GetMinWayToFinish(kingX, kingY);
    int controlCounter = 0;
    int winner = 1;

    while (controlCounter < minWayToFinish)
    {
        if ((controlCounter % 2) == 0 || SpecialCheckKingPosition (kingX, kingY))
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }

        controlCounter++;
    }

    return winner;
}

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
    int gamesCount = 0;
    while (getline(inputFile, fileLine))
    {
        if (strCounter == 0)
        {
            gamesCount = stoi(fileLine);
        }
        else
        {
            vector<int> parseKingCoordinate = SplitIntegers(fileLine, ' ');
            outputFile << KingGameImitation (parseKingCoordinate[0], parseKingCoordinate[1]) << endl;
        }
        strCounter++;
    }
    return 0;
}