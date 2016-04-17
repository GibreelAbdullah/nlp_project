count = 0 
with open("read.txt","r") as f:
	for line in f:
		word = line[16:]
		word1 = int(word)
		count = count + word1


print(count)