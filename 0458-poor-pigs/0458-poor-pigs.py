class Solution:
    def poorPigs(self, b, m, n):
        c = 0
        while math.pow(n // m + 1, c) < b:
            c += 1
        return c