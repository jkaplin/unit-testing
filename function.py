#!/bin/python
import ctypes
import sys

orig_stdout = sys.stdout
f = open('out.txt', 'w')
sys.stdout = f

NUM = 16      
# libfun loaded to the python file 
# using fun.myFunction(), 
# C function can be accessed 
# but type of argument is the problem. 
                         
fun = ctypes.CDLL("libfun.so")   
# Now whenever argument  
# will be passed to the function                                                         
# ctypes will check it. 
  
# now we can call this  
# function using instant (fun) 
# returnValue is the value  
# return by function written in C  
# code 
returnVale = fun.myFunction(NUM)
print returnVale

sys.stdout = orig_stdout
f.close()
