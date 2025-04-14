#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main() {
    // Define the vector of shapes
    vector<string> v = {"Tetrahedron", "Cube", "Octahedron", "Dodecahedron", "Icosahedron"};
    
    // Map each shape to its number of sides
    map<string, int> sides = {
        {"tetrahedron", 4},
        {"cube", 6},
        {"octahedron", 8},
        {"dodecahedron", 12},
        {"icosahedron", 20}
    };
    
    int n;
    cin >> n;
    int total_sides = 0;
    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        total_sides += sides[s];
    }
    
    cout << total_sides << endl;
    return 0;
}