/**Question 8**

Given a string, count total number of consonants in it. A consonant is an English alphabet character that is not vowel (a, e, i, o and u). Examples of constants are b, c, d, f, and g.
*/

// SOLUTION
bool isConsonant(char ch)
{
   
    ch = toupper(ch);
  
    return !(ch == 'A' || ch == 'E' || 
            ch == 'I' || ch == 'O' || 
            ch == 'U') && ch >= 65 && ch <= 90;
}

int totalConsonants(string str, int n)
{
    if (n == 1)
        return isConsonant(str[0]);
  
    return totalConsonants(str, n - 1) + 
           isConsonant(str[n-1]);
}