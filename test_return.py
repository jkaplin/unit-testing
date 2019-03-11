#!/bin/bash/python3

import os
import difflib
from sys import argv
from subprocess import call, Popen

your_function = argv[1]
expected = argv[2]

#discover what type expected is by reading argv[1]:

int / long/ size_t... : only numbers -> a number: "123"
char / unsigned char / character -> character: "hello there"
pointer to number / char: array -> either array of chars (strings): ['a', 'c', 'd']  or of numbers: / array of numbers: "[3, 234, 2345]"
pointer to pointer... "["asdf", "asdf"]" or "[asdf, asdf]" 

os.system(transfer_to_file)

if (not os.path.isfile(expected)):
    transfer_to_file = "echo " + "\"" + expected + "\"" + " > " + "true_out"
    os.system(transfer_to_file)
else:
    copy_expected_to_true_out_file = "cp " + expected + " true_out"
    os.system(copy_expected_to_true_out_file)
print("                       YOUR PRINTOUT                          |                  EXPECTED PRINTOUT")
os.system("diff -y your_out true_out")
