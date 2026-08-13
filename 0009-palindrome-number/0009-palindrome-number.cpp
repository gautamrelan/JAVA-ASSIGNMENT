class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes (e.g., -121 -> 121-).
        // Also, if the last digit is 0, the first digit must be 0, which only happens for 0 itself.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNumber = 0;
        // Reverse only the second half of the number
        while (x > reversedNumber) {
            reversedNumber = reversedNumber * 10 + x % 10;
            x /= 10;
        }

        // For even-length numbers: x == reversedNumber (e.g., 1221 -> x = 12, reversedNumber = 12)
        // For odd-length numbers: x == reversedNumber / 10 (e.g., 12321 -> x = 12, reversedNumber = 123)
        return x == reversedNumber || x == reversedNumber / 10;
    }
};