#This class our struct format
#class Entry(object):
#	def_init_(self, name, zip, email, number):
#		self.name = name
#		self.zip = zip
#		self.email = email
#		self.number = number
#import sys


# list containing tuples

Entry = [("Name", "Zip", "Email", "Number")]
count = 0
insert = 0
adressList = []
while True:
	import sys
	if sys.argv[1] == 'ADD':
		if count < 5:
			if len(sys.argv[2]) <= 20 and sys.argv[2].isalpha():
				if len(sys.argv[3].zip) == 5 and sys.argv[3].isdigit():
					if #check email
					
						if #check number
							addressList.append(Entry(insert))
							addressList[insert].name = sys.argv[2]
							addressList[insert].zip = sys.argv[3]
							addressList[insert].email = sys.argv[4]
							addressList[insert].number = sys.argv[5]
							count = count + 1
							insert = insert + 1
		else:
			print(:there is 5 entries, can not take in more
	if sys.argv[1] == 'DEL':
		if count > 0:
			for i in range(insert):
				if addressList[i].name == sys.argv[2] and sys.argv[3] == None:
					addressList[i].name = None
					addressList[i].zip = None
					addressList[i].email = None
					addressList[i].number = None
					count = count - 1
				else:
					print("can not find requested person or invalid call of function - choose help")
		else:
			print("there are 0 entries in the address database, can not delete")
		
	if sys.argv[1] == 'GET':
		if sys.argv[3] == None:
			for i in range(insert):
				if addressList[i].name == sys.argv[2]:
					print("found requested person")
					print(addressList[i].name)
					print(addressList[i].zip)
					print(addressList[i].email)
					print(addressList[i].number)
		else:
			print("did not find requested person or invalid request of function - choose help")
	if sys.argv[1] == 'HELP':
		print("you need to have the parameters, in a specific order")
		print("for using the three functions - ADD, DEL, GET"):
		print("ADD - name zip email number")
		print("GET - name")
		print("DEL - name")
		print("if you do not have these parameters then the function will not execute")
	if sys.argv[1] == 'EXIT':
		exit()
