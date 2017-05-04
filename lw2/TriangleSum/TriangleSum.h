#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>

const std::vector<int> SplitIntegers(const std::string& targetString, const char& delimiter);
void CalculateTriangleMaxSum(int triangleWeight, std::vector<std::vector<int>>& vectorOfTriangleData,
                             std::ofstream& outputFile);