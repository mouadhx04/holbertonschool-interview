#!/usr/bin/python3
"""
0-pascal_triangle
"""


def pascal_triangle(n):
    """
    Returns a list of integers representing Pascal's triangle
    """
    lst = [[] for i in range(0, n)]
    for i in range(0, n):
        for j in range(i + 1):
            if (j < i):
                if (j <= 0):
                    lst[i].append(1)
                else:
                    lst[i].append(lst[i - 1][j] + lst[i - 1][j - 1])
            elif (i == j):
                lst[i].append(1)
    return (lst)
