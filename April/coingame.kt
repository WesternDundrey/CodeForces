import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val s = reader.readLine()
    val n = s.length
    val q = reader.readLine().toInt()

    // Initialize prefix sum arrays (size n+1 for easier range queries)
    val prefixG = IntArray(n + 1)
    val prefixS = IntArray(n + 1)
    val prefixB = IntArray(n + 1)

    // Calculate prefix sums
    // prefixX[i] stores the count of coin type X in the first i characters (s[0...i-1])
    for (i in 0 until n) {
        prefixG[i + 1] = prefixG[i]
        prefixS[i + 1] = prefixS[i]
        prefixB[i + 1] = prefixB[i]
        when (s[i]) {
            'G' -> prefixG[i + 1]++
            'S' -> prefixS[i + 1]++
            'B' -> prefixB[i + 1]++
        }
    }

    val results = StringBuilder()

    // Process each query
    repeat(q) {
        // Read query range [l, r] (1-based)
        val line = reader.readLine()
        val parts = line.split(" ")
        val l = parts[0].toInt()
        val r = parts[1].toInt()

        // Calculate the count of each coin type in the range [l, r]
        // Count in range [l, r] = prefix[r] - prefix[l-1]
        val countG = prefixG[r] - prefixG[l - 1]
        val countS = prefixS[r] - prefixS[l - 1]
        val countB = prefixB[r] - prefixB[l - 1]
        val scoreIfG = countG + min(countS, countB)
        // Calculate potential score if Player 1 chooses Silver first
        val scoreIfS = countS + min(countG, countB)
        // Calculate potential score if Player 1 chooses Bronze first
        val scoreIfB = countB + min(countG, countS)

        // The maximum score Player 1 can guarantee is the max of the three possibilities
        val maxScore = max(scoreIfG, max(scoreIfS, scoreIfB))

        // Append the result for this query
        results.append(maxScore).append("\n")
    }
    // Print all results
    print(results)
}