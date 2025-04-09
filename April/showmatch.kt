import java.util.*

// Function to solve a single test case
fun solve() {
    // Read the value of n (number of pairs)
    val n = readLine()!!.toInt()
    // Read the 2n ratings, convert them to integers, split by space,
    // map to Int, and sort the resulting list.
    val s = readLine()!!.split(" ").map { it.toInt() }.sorted()

    // Assume that a valid pairing is possible by default
    var possible = true

    // Iterate through the potential pairs. Since the list 's' is sorted,
    // the only candidate pairing is (s[0], s[1]), (s[2], s[3]), ..., (s[2n-2], s[2n-1]).
    // We check each pair (s[2*i], s[2*i+1]).
    for (i in 0 until n) {
        // Get the two players in the current potential pair
        val p1 = s[2 * i]
        val p2 = s[2 * i + 1]
        // Calculate the rating difference within this pair
        val currentDiff = p2 - p1 // Since s is sorted, p2 > p1

        // Condition 1: Check if p2 is a best opponent for p1.
        // p1's neighbors in the sorted list are s[2*i - 1] (if i > 0) and p2 (s[2*i + 1]).
        // If s[2*i - 1] exists, the difference to it is (p1 - s[2*i - 1]).
        // For p2 to be a best opponent, currentDiff must be <= prevDiff.
        if (i > 0) { // Check if the left neighbor s[2*i - 1] exists
            val prevNeighbor = s[2 * i - 1]
            val prevDiff = p1 - prevNeighbor
            if (currentDiff > prevDiff) {
                // If the difference to p2 is greater than the difference to the previous neighbor,
                // then p2 is not a best opponent for p1. The pairing is impossible.
                possible = false
                break // Exit the loop early
            }
        }

        // Condition 2: Check if p1 is a best opponent for p2.
        // p2's neighbors in the sorted list are p1 (s[2*i]) and s[2*i + 2] (if i < n - 1).
        // If s[2*i + 2] exists, the difference to it is (s[2*i + 2] - p2).
        // For p1 to be a best opponent, currentDiff must be <= nextDiff.
        if (i < n - 1) { // Check if the right neighbor s[2*i + 2] exists
            val nextNeighbor = s[2 * i + 2]
            val nextDiff = nextNeighbor - p2
             if (currentDiff > nextDiff) {
                // If the difference to p1 is greater than the difference to the next neighbor,
                // then p1 is not a best opponent for p2. The pairing is impossible.
                possible = false
                break // Exit the loop early
            }
        }
    }

    // After checking all pairs, print the result
    if (possible) {
        println("YES")
    } else {
        println("NO")
    }
}

// Main function to handle multiple test cases
fun main() {
    // Read the number of test cases
    val t = readLine()!!.toInt()
    // Run the solve function for each test case
    repeat(t) {
        solve()
    }
}