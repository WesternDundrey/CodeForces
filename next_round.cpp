#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int score;
    int kthScore = 0;
    int advancers = 0;
    
    // We'll store scores in an array for easy access.
    int scores[50];
    
    // Read scores
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    // The k-th participant's score (using 0-indexing)
    kthScore = scores[k - 1];
    
    // Count the number of participants who advance:
    // They must have a score >= kthScore and a positive score.
    for (int i = 0; i < n; i++) {
        if (scores[i] >= kthScore && scores[i] > 0) {
            advancers++;
        }
    }
    
    cout << advancers << endl;
    return 0;
}
