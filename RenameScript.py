#!/usr/bin/env python3.2
import os

obj=os.walk(r"/home/ryder/Файлы/Документы/Работа/UnitCoin/unitcoin")
xlist={}
s=input("Введите список для замены имён:\n").split(" ")
while len(s)>1 and len(s)<3:
	xlist[s[0]]=s[1]
	s=input().split(" ")
for x in obj:
	if not "/home/ryder/Файлы/Документы/Работа/UnitCoin/unitcoin/.git" in x[0]:
		for y in x[1]:
			s=y
			for z in xlist:
				s=s.replace(z,xlist[z])
			if s!=y:
				os.rename(x[0]+r"/"+y,x[0]+r"/"+s)
		for y in x[2]:
			f=open(x[0]+r"/"+y,"r")
			try:
				s=f.read()
				for z in xlist:
					s=s.replace(z,xlist[z])
				f.close()
				f=open(x[0]+r"/"+y,"w")
				f.write(s)
			except:
				pass
			s=y
			for z in xlist.keys():
				s=s.replace(z,xlist[z])
			os.rename(x[0]+r"/"+y,x[0]+r"/"+s)
