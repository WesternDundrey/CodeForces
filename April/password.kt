import java.util.Scanner

fun main() {
    val reader = Scanner(System.`in`)
    val t = reader.nextInt()
    val digits = "0123456789"
    val upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    val lower = "abcdefghijklmnopqrstuvwxyz"

    repeat(t) {
        val a = reader.nextInt()
        val b = reader.nextInt()
        val c = reader.nextInt()
        val password = StringBuilder()
        password.append(digits.take(a))
        password.append(upper.take(b))
        password.append(lower.take(c))
        println(password.toString())
    }
}