#!/usr/bin/python3
''' Find amount of coins that adds to a specific total '''


def makeChange(coins, total):
    ''' find num of coins that make the total '''
    if (total <= 0):
        return 0
    if total in coins:
        return 1
    numCoins = 0
    currCoin = 0
    coins = reversed(sorted(coins))

    for coin in coins:
        while currCoin + coin <= total:
            numCoins += 1
            currCoin += coin
    if currCoin != total:
        return -1
    return numCoins
