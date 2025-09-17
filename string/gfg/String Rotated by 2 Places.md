# String Rotation by 2 Places

## Problem Statement

Given two strings `s1` and `s2`, return `true` if the string `s2` can be
obtained by rotating (in any direction) string `s1` by exactly **2
places**, otherwise return `false`.

Both rotations should be performed in the same direction chosen
initially.

### Examples

#### Example 1

**Input:**\
s1 = "amazon", s2 = "azonam"\
**Output:**\
true\
**Explanation:**\
"amazon" can be rotated anti-clockwise by two places, which will make it
"azonam".

#### Example 2

**Input:**\
s1 = "geeksforgeeks", s2 = "geeksgeeksfor"\
**Output:**\
false\
**Explanation:**\
If we rotate "geeksforgeeks" by two places in any direction, we won't
get "geeksgeeksfor".

#### Example 3

**Input:**\
s1 = "ab", s2 = "ab"\
**Output:**\
true\
**Explanation:**\
If we rotate "ab" by two places in any direction, we always get "ab".

------------------------------------------------------------------------

## Constraints

-   1 ≤ s1.length, s2.length ≤ 10\^5

### Expected Complexities

-   Time Complexity: **O(n)**
-   Auxiliary Space: **O(1)**

------------------------------------------------------------------------

## C++ Solution

``` cpp
class Solution {
public:
    void rotateClockWise(string &clockWiseString) {
        int secondLast = clockWiseString.size() - 2;
        int start = 0;
        char lastChar = clockWiseString[clockWiseString.size() - 1];

        while (secondLast >= start) {
            clockWiseString[secondLast + 1] = clockWiseString[secondLast];
            secondLast--;
        }

        clockWiseString[0] = lastChar;
    }

    void rotateAntiClockWise(string &antiClockWiseString) {
        int lastIndex = antiClockWiseString.size() - 1;
        int start = 1;
        char firstChar = antiClockWiseString[0];

        while (start <= lastIndex) {
            antiClockWiseString[start - 1] = antiClockWiseString[start];
            start++;
        }

        antiClockWiseString[lastIndex] = firstChar;
    }

    bool isRotated(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;

        string cw = s1;
        string acw = s1;

        rotateClockWise(cw);
        rotateClockWise(cw);
        if (cw == s2) {
            return true;
        }

        rotateAntiClockWise(acw);
        rotateAntiClockWise(acw);
        if (acw == s2) {
            return true;
        }

        return false;
    }
};
```
