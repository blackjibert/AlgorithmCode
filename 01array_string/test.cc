#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// Function to sort a string
string sortString(const string& str) {
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
}

// Function to classify the strings
int classifyStrings(const vector<string>& strings) {
    unordered_map<string, int> classifiedStrings;
    int numClasses = 0;

    for (const std::string& str : strings) {
        std::string sortedStr = sortString(str);
        if (classifiedStrings.find(sortedStr) == classifiedStrings.end()) {
            classifiedStrings[sortedStr] = numClasses++;
        }
    }

    return numClasses;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> strings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }

    int numClasses = classifyStrings(strings);
    std::cout << numClasses << std::endl;

    return 0;
}