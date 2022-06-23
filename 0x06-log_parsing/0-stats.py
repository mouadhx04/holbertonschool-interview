#!/usr/bin/python3
"""
read stdin line by line and computes metrics
"""
import sys
STATUS = {'200': 0, '301': 0,
          '400': 0, '401': 0,
          '403': 0, '404': 0,
          '405': 0, '500': 0}
size = 0
lines = 0
try:
    for argument in sys.stdin:
        argumentList = argument.split(" ")
        if len(argumentList) > 2:
            status = argumentList[-2]
            fileSize = int(argumentList[-1])
            if status in STATUS:
                STATUS[status] += 1
            size += fileSize
            lines += 1
            if lines == 10:
                print("File size: {:d}".format(size))
                for key, value in sorted(STATUS.items()):
                    if value != 0:
                        print("{}: {:d}".format(key, value))
                lines = 0
finally:
    print("File size: {:d}".format(size))
    for key, value in sorted(STATUS.items()):
        if value != 0:
            print("{}: {:d}".format(key, value))
