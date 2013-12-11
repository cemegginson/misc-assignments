#!/usr/bin/python
#Diophantine McNuggets
#By Casey Megginson
#Find the highest number of McNuggets that can't be purchased
#with any combination of 6, 9, and 20 packs.

mc6 = 0
mc9 = 0
mc20 = 0
flag = 0
counter = 0
total = 0

while counter < 6:
	total += 1
	flag = 0
	for mc20 in range(0, int(total / 20 + 1)): #Testing 20s
		for mc9 in range(0, int(total / 9 + 1)): #Testing 9s
			for mc6 in range(0, int(total / 6 + 1)): #Testing 6s
				if mc6 * 6 + mc9 * 9 + mc20 * 20 == total: 
					flag = 1 #If it works, set a flag
	if flag == 0: 
		lastnum = total
		counter = 0
	else:
		counter += 1

print(lastnum) # And print our answer
