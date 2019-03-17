#!/bin/bash/python3

from os import system, path
from sys import argv, exit

if (len(argv) != 3):
    exit("usage: python test_print.py your_binary_file expected_output")

your_binary = argv[1]
expected = argv[2]

transfer_to_file = "./" + your_binary + " > " + "your_out.trace"
system(transfer_to_file)

if (not path.isfile(expected)):
    transfer_to_file = "echo " + "\"" + expected + "\"" + " > " + "true_out.trace"
    system(transfer_to_file)
else:
    copy_expected_to_true_out_file = "cp " + expected + " true_out.trace"
    system(copy_expected_to_true_out_file)

your_output_file = open("your_out.trace", "r")
true_output_file = open("true_out.trace", "r")
if (your_output_file.read() == true_output_file.read()):
    print("SUCCESS!")
else:
    print("FAILURE! Here's the difference:\n")
    print("                       YOUR PRINTOUT                          |                  EXPECTED PRINTOUT")
    system("diff -y your_out.trace true_out.trace")
