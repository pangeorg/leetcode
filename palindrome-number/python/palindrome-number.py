#!/usr/bin/python3

import math
def isPalindrome(x: int) -> bool:
    if x < 0: return False
    r = []
    for i in range(int(math.log10(x)), -1, -1):
        exp = 10**(i)
        f = int(x/exp)
        r.append(f)
        x = x - f*exp
    return r == r[::-1]


if __name__ == "__main__":
    print("Running tests...")
    assert isPalindrome(141) == True
    assert isPalindrome(-141) == False
    assert isPalindrome(10) == False
    print("Passed all tests!")
