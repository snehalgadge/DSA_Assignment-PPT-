/*<aside>
💡 **Question 4**

Given a string calculate length of the string using recursion.

**Examples:**
Input : str = "abcd"
Output :4
*/

// SOLUTION
int recLen(char* str)   
{
    // if we reach at the end of the string
    if (*str == '\0')
        return 0;
    else
        return 1 + recLen(str + 1);
}