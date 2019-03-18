#!/bin/python3

from subprocess import Popen

def make_list(folder, name, num):
    tests = []
    i = 0
    while (i < num):
        test = folder + name + str(i) + ".txt"
        tests.append(test)
        i += 1
    return tests

tests = make_list("tests/", "test", 7)
error_tests = make_list("error_tests/", "test_error", 2)
for test in tests:
    print("\n\033[1;32;40m Test\033[0m\n")
    Popen(["cat",  test, ">>", "trace.txt"])
    print("\n\033[1;32;40m Your Output\033[0m\n")
    Popen(["time", "./fillit",  test, ">>", "trace.txt"])

print("\nERROR Tests\n")
for error_test in error_tests:
    print("\n\033[1;31;40m Error Test\033[0m\n")
    Popen(["cat", error_test, ">>", "trace.txt"])
    print("\n\033[1;31;40m Your Output\033[0m\n")
    Popen(["./fillit", error_test, ">>", "trace.txt"])
