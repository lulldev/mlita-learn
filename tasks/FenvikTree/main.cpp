#include <iostream>
#include <vector>
#include <fstream>

#include "FenvikTree/Helpers.h"

using namespace std;

std::vector<int> t;
int n;

void init (int nn)
{
    n = nn;
    t.assign (n, 0);
}

void add (int i, int delta)
{
    for (; i < n; i = (i | (i+1)))
    {
        t[i] += delta;
    }
}

void init (vector<int> a)
{
    init ((int) a.size());
    for (unsigned i = 0; i < a.size(); i++)
    {
        add (i, a[i]);
    }
}

int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
    {
        result += t[r];
    }
    return result;
}

int sum (int l, int r)
{
    return sum (r) - sum (l-1);
}

void ShowTree()
{
    for (int i = 0; i < t.size(); i++)
    {
        cout << i << ":" << t[i] << endl;
    }
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
            arrayElements = SplitIntegersFromString(fileLine, ' ');
        }
        strCounter++;
    }

    init(arrayElements);

    cout << "Builded tree ready:" << endl;
    ShowTree();

    string inputMenuItem;
    string command;

    cout << "Fenvik commands:\n"
         << "1 - Add (i, d)\n"
         << "2 - Rsq (i, j)\n"
         << "3 - Show tree\n"
         << "Input your command >>";

    while(cin >> inputMenuItem)
    {
        if (isdigit(inputMenuItem[0]))
        {
            if (inputMenuItem == "1")
            {
                int i, d;
                cout << "Input i = ";
                cin >> i;
                cout << "Input d = ";
                cin >> d;
                add(i, d);
                ShowTree();
            }
            else if (inputMenuItem == "2")
            {
                int i, j;
                cout << "Input i = ";
                cin >> i;
                cout << "Input j = ";
                cin >> j;
                cout << sum (i, j) << endl;
            }
            else if (inputMenuItem == "3")
            {
                ShowTree();
            }
            else
            {
                cout << "Unknow command. Input please [1-3]." << endl;
            }
        }
        else
        {
            cout << "Input number of command [1-3]" << endl;
        }
        cout << "Input your command [1-3] >>";
    }


    return 0;
}