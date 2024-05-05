class Solution {
public:
 bool isDigit(char ch) {
    // Check if the character is between '0' and '9'
    return (ch >= '0' && ch <= '9');
}
    bool isUppercase(char ch) {
    // Check if the character is in the range of uppercase letters
    return (ch >= 'A' && ch <= 'Z');
}
    bool isConsonant(char ch) {
    // Convert the character to lowercase for ease of comparison
    ch = tolower(ch);

    // Check if the character is an alphabet and not a vowel
    return isalpha(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
    bool isVowel(char ch) {
    // Convert the character to lowercase for ease of comparison
    ch = tolower(ch);

    // Check if the character is one of the vowels
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
bool isValid(string word) {
    if (word.size() < 3) return false;

    bool hasDigit = false;
    bool hasUppercase = false;
    bool hasConsonant = false;
    bool hasVowel = false;

    for (char ch : word) {
        if (isdigit(ch)) hasDigit = true;
         if (isUppercase(ch)) hasUppercase = true;
         if (isConsonant(ch)) hasConsonant = true;
     if (isVowel(ch)) hasVowel = true;
        
        if(!(( isdigit(ch) || isUppercase(ch)) || isConsonant(ch) ||isVowel(ch)) )
            return false;

    }

    return( hasDigit || hasUppercase) && hasConsonant && hasVowel;
}
};