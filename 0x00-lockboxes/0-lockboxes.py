#!/usr/bin/python3
"""
lockboxes , we have n number  of locked boxes in front of you.
 Each box is numbered sequentially from 0 to
 n - 1 and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    '''determines if all the boxes can be opned'''
    open = [0]
    for i in open:
        for box in boxes[i]:
            if box not in open:
                if box < len(boxes):
                    open.append(box)
    if len(open) == len(boxes):
        return True
    return False
