#!/usr/bin/python
# import os
import random
import sys

if len(sys.argv) < 2:
	print("Error: not enough arguments")
	exit(0)
array = []
for i in range(int(sys.argv[1])):
	while True:
		try:
			new_random = random.randint(-2147483648, 2147483647)
			found = False
			for num in array:
				if new_random == num:
					raise Exception()
			array.append(new_random)
			break
		except:
			pass
args = ""
for n in array:
	args = args + str(n) + " "
with open("input", 'w') as f:
	f.write(args)
	f.close()
# print("./push_swap " + args)
# os.system("./push_swap " + args)
