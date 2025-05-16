def longest_palindrome(s: str):
    if len(s) == 1:
        return s
    if is_palindrome(s):
        return s
    if len(s) == 2:
        return s[1]
    window_size = len(s) - 1
    while window_size >= 1:
        start = 0
        while True:
            next = start + window_size
            if next > len(s):
                break
            if next == len(s):
                substring = s[start:]
            else:
                substring = s[start:next]
            # print(start, next, window_size, substring)
            if is_palindrome(substring):
                return substring
            start += 1
        window_size -= 1
    return ""


def is_palindrome(s: str) -> bool:
    return s == s[::-1]


assert longest_palindrome("cbbd") == "bb"
assert longest_palindrome("babad") == "bab"
assert longest_palindrome("bb") == "bb"
assert longest_palindrome("abb") == "bb"
