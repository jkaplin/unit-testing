#!/bin/bash/python3

import os
from sys import argv
from subprocess import call, Popen

your_binary = argv[1]
expected = argv[2]

transfer_to_file = "./" + your_binary + " > " + ".your_out"
os.system(transfer_to_file)

if (not os.path.isfile(expected)):
    transfer_to_file = "echo " + "\"" + expected + "\"" + " > " + ".true_out"
    os.system(transfer_to_file)
else:
    copy_expected_to_true_out_file = "cp " + expected + " .true_out"
    os.system(copy_expected_to_true_out_file)
your_file = open(".your_out", "r")
true_file = open(".true_out", "r")
if (your_file.read() == true_file.read()):
    print("SUCCESS!")
else:
    print("FAILURE! Here's the difference:\n")
    print("                       YOUR PRINTOUT                          |                  EXPECTED PRINTOUT")
    os.system("diff -y .your_out .true_out")
