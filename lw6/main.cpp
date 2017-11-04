#include <iostream>
#include <vector>
#include <fstream>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

using namespace std;

struct Point
{
    int x;
    int y;
};

bool IsOnSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
    {
        return true;
    }
    return false;
}

// To find orientation of ordered triplet (p, q, r).
// http://www.geeksforgeeks.org/orientation-3-ordered-points/
int GetOrientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
    {
        return 0;
    }

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool IsSegmentsHasOveralPoint(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = GetOrientation(p1, q1, p2);
    int o2 = GetOrientation(p1, q1, q2);
    int o3 = GetOrientation(p2, q2, p1);
    int o4 = GetOrientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
    {
        return true;
    }

    if (o1 == 0 && IsOnSegment(p1, p2, q1))
    {
        return true;
    }

    if (o2 == 0 && IsOnSegment(p1, q2, q1))
    {
        return true;
    }

    if (o3 == 0 && IsOnSegment(p2, p1, q2))
    {
        return true;
    }

    if (o4 == 0 && IsOnSegment(p2, q1, q2))
    {
        return true;
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

    struct Point p1 = {fX1, fY1}, q1 = {fX2, fY2};
    struct Point p2 = {sX1, sY1}, q2 = {sX2, sY2};

    outputFile << (IsSegmentsHasOveralPoint(p1, q1, p2, q2) ? "Yes" : "No");

    return 0;
}
