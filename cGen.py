
f = open('Cgen.txt', 'w')


with open ("test.txt", "r") as myfile:
    data=myfile.read().replace('\n', '')
	
print(data[1])
num = 0

f.write('int prbs[] = {\n')
for i in range( ((len(data))//8)  ):
	
	f.write("'0b" + data[i:i+8] +"'")
	if( i != (((len(data))//8) -1) ):
		f.write(", ")
	num = num + 1
	if (num == 7):
		f.write("\n")
		num = 0
		
f.write(");")
		

	




