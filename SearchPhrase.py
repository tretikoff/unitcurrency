#!/usr/bin/env python3.2
import os

obj=os.walk(r"/home/ryder/Файлы/Документы/Работа/UnitCoin/unitcoin")
phrase=input()
for x in obj:
	for y in x[2]:
		try:
			f=open(x[0]+"/"+y,"r")
			s=f.read()
			if phrase in s:
				print(x[0]+"/"+y)
		except:
			pass
