#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const string inputFileName = "input.txt";
const string outputFileName = "output.txt";
const int ENTRANCE_COUNT = 3;

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

// unused
void FindStepPattern (int n, int k, int x, int y, int& pStep, int& pCount)
{
    int i = 1;
    string control;
    while (i <= n)
    {
        if (i == 1)
        {
            if (i % k == 0)
            {
                control = "x";
            }
            else
            {
                control = "y";
            }
        }
        if (control == "x" && (i % k == 0))
        {
            pCount += x;
            pStep++;
        }
        else if (control == "y" && (i % k != 0))
        {
            pCount += y;
            pStep++;
        }
        else
        {
            if (control == "x")
            {
                pCount += y;
            }
            else
            {
                pCount += x;
            }
            break;
        }
        i++;
    }
}

int GetRoomCountInOneEntrance (int n, int k, int x, int y)
{
    int roomCount = 0;
    int i = 1;
    while (i <= n)
    {
        if ((i % k == 0))
        {
            roomCount += x;
        }
        else
        {
            roomCount += y;
        }
        i++;
    }
    return roomCount;
}

int FindFloorByRoomNo (int roomNo, int roomCountOneEntrance, int n, int k, int x, int y)
{
    int startRoom = 1;
    int endRoom = roomCountOneEntrance;
    int floor = -1;

    while (startRoom  < roomCountOneEntrance * ENTRANCE_COUNT)
    {
        if (roomNo >= startRoom && roomNo <= endRoom)
        {
            int tmpStartRoom = startRoom;
            int floorCounter = 1;
            while (floorCounter <= n)
            {
                if ((tmpStartRoom) + x > roomNo || (tmpStartRoom) + y > roomNo)
                {
                    return (floorCounter);
                }

                if ((floorCounter % k == 0))
                {
                    tmpStartRoom += x;
                }
                else
                {
                    tmpStartRoom += y;
                }
                floorCounter++;
            }
        }

        startRoom += roomCountOneEntrance;
        endRoom += roomCountOneEntrance;
    }
    return floor;
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

    int roomCountOneEntrance = GetRoomCountInOneEntrance (n, k, x, y);

    for (auto &room : targetRooms)
    {
        outputFile << FindFloorByRoomNo(room, roomCountOneEntrance, n, k, x, y) << endl;
    }

    return 0;
}