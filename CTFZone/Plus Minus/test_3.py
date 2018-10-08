#!/usr/bin/env python

import inspect
import ast
import itertools
import sys 
import os
import socket
import time
from random import shuffle
import sys, socket, struct
from pwn import *

def isFloat(s):
	try:
		float(s)
	except ValueError:
		return False
	return True

def checkCalc(s):
	try:
		e = eval(s)
	except ZeroDivisionError:
		return False
	except SyntaxError:
		return False
	return e

def adding_a_parenthese(arr):
	result = []
	for i in range(0, len(arr) - 1):
		tmp = []
		for j in range(0, i):
			tmp.append(arr[j])
		tmp.append('(')
		tmp.append(arr[i])
		tmp.append(arr[i + 1])
		tmp.append(')')
		tmp.extend(arr[i+2:])
		result.append(tmp)
	return result

def concentrate(head, tail):
	res = []
	for i in head:
		res.append(i)
	for i in tail:
		res.append(i)
	return res

def cut_down_parenthese_pair(arr):
	head = []
	for i in range(0, len(arr)):
		head.append(arr[i])
		if(arr[i] == ')'):
			return (head, arr[i+1:])

def adding_operation(arr, operation_str):
	res = []
	j = 0
	for i in range(0, len(arr)):
		res.append(arr[i])
		if(isFloat(arr[i]) == True and i != len(arr) - 1):
			if(arr[i + 1] != ")" ):
				res.append(operation_str[j])
				j += 1
		else:
			if(arr[i] == ')' and i != len(arr) - 1):
				res.append(operation_str[j])
				j += 1
	return res

def int_to_float(arr):
	for i in range(0, len(arr)):
		if(isFloat(arr[i]) == True):
			arr[i] = str(float(arr[i]))
	return arr

def expanse_parenthese(arr):
	pos = arr.index('(')
	if(pos - 2 > 0 and pos + 4 < len(arr)):
		arr.insert(pos - 2, '(')
		arr.insert(pos + 5, ')')
	else:
		return False
	return arr

r = remote("ppc-01.v7frkwrfyhsjtbpfcppnu.ctfz.one", 2445)
while(True):
	print "1:"
	rec = so.recv(2048)
	print rec
	#Extract from input
	st = rec
	s = st.split()
	chars = "+-*/"
	op_str_arr = []
	expect = float(s[len(s) - 1])
	s.pop()
	count = len(s) - 1	

	#generate operator list
	for item in itertools.product(chars, repeat=count):
		op_str_arr.append("".join(item))
	# print op_str_arr
	#generate parenthese list
	all_possible = adding_a_parenthese(s)
	for c in adding_a_parenthese(s):
		head, tail = cut_down_parenthese_pair(c)
		for t in adding_a_parenthese(tail):
			res = concentrate(head, t)
			all_possible.append(res)
			head_2, tail_2 = cut_down_parenthese_pair(t)
			for n in adding_a_parenthese(tail_2):
				res = concentrate(head_2, n)
				res = concentrate(head, res)
				all_possible.append(res)	

	# print len(all_possible)
	all_possible_op = []	

	for op_str in op_str_arr:
		for possible in all_possible:
			all_possible_op.append(adding_operation(possible, op_str))
	all_possible_op.reverse()
	for test in all_possible_op:
		expanse = expanse_parenthese(test)
		if(expanse != False):
			all_possible_op.append(expanse)	

	calculated = 0
	# test = ["1", "+", "2", "/", "(","4", "+", "3", ")", "+", "(", "9", "+", "1", ")", "-", "5"]
	# # print all_possible_op.index(test)
	# print eval("".join(int_to_float(all_possible_op[53218])))
	# f = open("res.txt", "wb")
	max_possible = len(all_possible_op)
	for pos_op in all_possible_op:
		cl = ("".join(int_to_float(pos_op)))
		checkcalc = checkCalc(cl)
		if(checkcalc != False):
			res = checkcalc
		else:
			res = 0
		# calculated += 1
		# if calculated == 53218:
		# 	print cl
		# 	print expect
		# 	print res
		# 	print type(expect)
		# 	print type(res)
		#f.write(cl + "\n")
		#f.write(str(float(res)) + "\n")
		if str(res) == str(expect):
			print cl
			r.send(cl)
			r.recv(4096)
			break
print "Done"