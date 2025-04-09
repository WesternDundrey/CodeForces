import kotlin.collections.ArrayList // Good practice to import if using ArrayList explicitly

fun main() {
    // 1. Get the word from the user
    println("Enter a word:")
    val yourWord = readln()

    // 2. Create a list to store the numbers
    val numbers = mutableListOf<Int>() // Use a mutable list to add numbers dynamically

    // 3. Read one number for each character in the word
    println("Enter ${yourWord.length} numbers, one per line:")
    for (i in yourWord.indices) { // Loop based on the length of the word
        print("Enter number ${i + 1}: ") // Prompt user for clarity
        try {
            val inputString = readln()   // Read the input as a String
            val number = inputString.toInt() // Convert the String to an Int
            numbers.add(number)          // Add the converted number to the list
        } catch (e: NumberFormatException) {
            // Handle cases where the user doesn't enter a valid number
            println("Invalid input. Please enter an integer. Exiting.")
            return // Stop the program if input is incorrect
        }
    }

    // 4. Process and display each number minus 1
    println("\nResults (each number minus 1):")
    for (n in numbers) { // Loop through the *list* of numbers you collected
        val result = n - 1 // Calculate n - 1
        println(result)    // Print the result
    }
}