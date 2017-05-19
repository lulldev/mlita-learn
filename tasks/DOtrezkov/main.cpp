#include <iostream>
#include <vector>
#include <fstream>

#include "Helpers.h"

#define MAX 10
using namespace std;

int n;
int arr[MAX];
int t[4*MAX];

void BuildSegmentationTreeForSum (int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        BuildSegmentationTreeForSum (a, v*2, tl, tm);
        BuildSegmentationTreeForSum (a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void BuildSegmentationTreeForMin (int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        BuildSegmentationTreeForMin (a, v*2, tl, tm);
        BuildSegmentationTreeForMin (a, v*2+1, tm+1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void Add (int v, int tl, int tr, int pos, int new_val)
{
    if (pos <= tl && tr <= pos)
    {
        t[v] = new_val;
        return;
    }
    if (tr < pos || pos < tl) {
        return;
    }
    int tm = (tl + tr) / 2;
    Add(v * 2, tl, tm, pos, new_val);
    Add(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

void AddForMin (int v, int tl, int tr, int pos, int new_val)
{
    if (pos <= tl && tr <= pos)
    {
        t[v] = new_val;
        return;
    }

    if (tr < pos || pos < tl) {
        return;
    }

    int tm = (tl + tr) / 2;
    AddForMin(v * 2, tl, tm, pos, new_val);
    AddForMin(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int Rsq (int v, int tl, int tr, int l, int r)
{
    if (l <= tl && tr <= r)
    {
        return t[v];
    }
    if (tr < l || r < tl)
    {
        return 0;
    }
    int tm = (tl + tr) / 2;
    return Rsq(v * 2, tl, tm, l, r) + Rsq(v * 2 + 1, tm + 1, tr, l, r);
}

int Rnq(int v, int tl, int tr, int l, int r)
{
    if (l <= tl && tr <= r)
    {
        return t[v];
    }
    if (tr < l || r < tl)
    {
        return INT_MAX;
    }
    int tm = (tl + tr) / 2;
    return min(Rnq(v * 2, tl, tm, l, r),
               Rnq(v * 2 + 1, tm + 1, tr, l, r));
}

void ShowTree()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ":" << t[i] << endl;
    }
}

int main(int argc, const char * argv[])
{
    if (argc != 2)
    {
        cout << "Program arguments startup error\n" << "Usage: program <input file>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);

    if (!inputFile.is_open())
    {
        cout << "Error i/o files: " << argv[1] << endl;
        return 1;
    }

    if (inputFile.fail())
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

    int* intArrayElements = arrayElements.data();
    n = elementsCount;

//    BuildSegmentationTreeForSum(intArrayElements, 1, 0, n - 1);
    BuildSegmentationTreeForMin(intArrayElements, 1, 0, n - 1);

    cout << "Builded tree ready!" << endl;

    string inputMenuItem;
    string command;

    cout << "SegmentationTree commands:\n"
         << "1 - Add (i, d)\n"
         << "2 - Rsq (i, j)\n"
         << "--------------\n"
         << "3 - AddForMin (i, d)\n"
         << "4 - Rnq (i, j)\n"
         << "--------------\n"
         << "5 - Show tree\n"
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
                Add (1, 0, n - 1, i, intArrayElements[i] + d);
                cout << "Element is add!" << endl;
            }
            else if (inputMenuItem == "2")
            {
                int i, j;
                cout << "Input i = ";
                cin >> i;
                cout << "Input j = ";
                cin >> j;
                cout << "Result: ";
                cout << Rsq (1, 0, n - 1, i, j) << endl;
            }
            else if (inputMenuItem == "3")
            {
                int i, d;
                cout << "Input i = ";
                cin >> i;
                cout << "Input d = ";
                cin >> d;
                AddForMin (1, 0, n - 1, i, intArrayElements[i] + d);
                cout << "Element is add!" << endl;
            }
            else if (inputMenuItem == "4")
            {
                int i, j;
                cout << "Input i = ";
                cin >> i;
                cout << "Input j = ";
                cin >> j;
                cout << "Result: ";
                cout << Rnq (1, 0, n - 1, i, j) << endl;
            }
            else if (inputMenuItem == "5")
            {
                ShowTree();
            }
            else
            {
                cout << "Unknow command. Input please [1-5]." << endl;
            }
        }
        else
        {
            cout << "Input number of command [1-5]" << endl;
        }
        cout << "Input your command [1-5] >>";
    }

    return 0;
}