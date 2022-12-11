#!/usr/bin/python3
"""0x19-Making Change."""


def makeChange(coins, total):
    """Change comes from within."""
    pocketChange = 0
    myCoins = 0
    coins = reversed(sorted(coins))

    if total <= 0:
        return (0)

    for coin in coins:
        while pocketChange + coin <= total:
            myCoins += 1
            pocketChange += coin

    if pocketChange != total:
        return (-1)
    return (myCoins)
