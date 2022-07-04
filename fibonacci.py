#!/bin/python3

import math
import os
import random
import re
import sys


def fibonacciModified(t1, t2, n):
    for i in range(2, n):
        Result = t1 + t2*t2
        t1 = t2
        t2 = Result
    # Basit bir döngü kullandım.
    # Büyük sayılarla C++ kodunda sıkıntı çıkınca bu kodu Python ile yazmak durumunda kaldım.   
    return Result    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    t1 = int(first_multiple_input[0])

    t2 = int(first_multiple_input[1])

    n = int(first_multiple_input[2])

    result = fibonacciModified(t1, t2, n)

    fptr.write(str(result) + '\n')

    fptr.close()
