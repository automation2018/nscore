#!/usr/bin/env python

import re

def grep(arr, pattern):
    regex = re.compile(pattern)
    
    return filter(regex.match, arr)
