#!/bin/bash/python3

import os
import difflib
from sys import argv
from subprocess import call, Popen

your_binary = argv[1]
expected = argv[2]

transfer_to_file = "./" + your_binary + " > " + "your_out"
os.system(transfer_to_file)

if (not os.path.isfile(expected)):
    transfer_to_file = "echo " + "\"" + expected + "\"" + " > " + "true_out"
    os.system(transfer_to_file)
else:
    copy_expected_to_true_out_file = "cp " + expected + " true_out"
    os.system(copy_expected_to_true_out_file)
print("                       YOUR PRINTOUT                          |                  EXPECTED PRINTOUT")
os.system("diff -y your_out true_out")

test_file = open(argv[1])
line = test_file.readline()
for word in line.split(" ")

create a main.c file with their function and the argumans that they pass into it




test file is always two words first is the function with the arguments, second is what they expect

FILE FORMAT:

my_min_function(4, 3) == 3 ?
my_other_function("this", "is_fun") == "break" ?
my_printf("Tricky") == "Tricky" ! #<< this means it's a void function but they want to test their printing

main_file = open(argv[?], "w")
main_file.write("#include <stdio.h>\n")
main_file.write("#include " + argv[?] + "\n")
main_file.write("int   main(int argc, char **argv)\n")
main_file.write("{\n")
main_file.write("\t" + type_from_line? + "\t" + pointer_stars_from_line? + "result;\n\n")
main_file.write("\t" + type_from_line? + "\t" + pointer_stars_from_line? + "expected;\n\n")
main_file.write("result = " + result_from_line? + ";\n")
main_file.write("#include <stdio.h>\n")
if_no_pointer_stars_from_line_then:
			if (mem_cmp(result, expected, length_from_line?))
				printf("SUCCESS");
			else
				printf("FAILURE");
			return (0);
else_then:
			if (mem_cmp(&result, &expected, 1))
				printf("SUCCESS");
			else
				printf("FAILURE");
			return (0);
		}
