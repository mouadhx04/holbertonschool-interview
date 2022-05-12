#!/usr/bin/python3
"""
Method that calculates the fewest number of operations
"""


def minOperations(n):
    """This method returns the number of operations to copy paste"""
    if n <= 1:
        return 0
    operation = 0
    divisor = 2
    quotient = n
    while quotient > 1:
        if (quotient % divisor) == 0:
            quotient = quotient // divisor
            operation += divisor
        else:
            divisor += 1
    return operation
