#!/usr/bin/python3
""" Module that change comes from within.
"""


def makeChange(coins, total):
    """ Method that determine the fewest number of coins needed
        to meet a given amount total.
        Args:
            coins: Is a list of the values of the coins in your possession.
            total: Total coins.
        Return:
            Fewest number of coins needed to meet total.
    """

    if total <= 0:
        return 0
    if coins is None or coins == []:
        return -1
    coins = sorted(coins, reverse=True)
    counter = 0
    for i in coins:
        if i <= total:
            counter += int(total / i)
            total = total % i
        if total == 0:
            return counter
    return -1
