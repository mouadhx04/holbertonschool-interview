#!/usr/bin/python3
"""
<<<<<<< HEAD
a list of (+) integers representing the heights of walls with unit width 1
=======
a list of positif integers representing the heights of walls with unit width 1
>>>>>>> cd6ab373bbb8b8a80842eb2fb2fc74a3e4aad854
"""


def rain(walls):
    """
    Args:
        walls - is a list of non-negative integers.
    Returns:
        If the list is empty return 0.
    """
    n = len(walls)
    total_water = 0

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        total_water = total_water + (min(left, right) - walls[i])
    return total_water
