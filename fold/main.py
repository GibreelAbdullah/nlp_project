import math

for i in range(0,10):
	j=str(i)
	vocabulary = j+"/vocabulary"+j+".txt"
	print (vocabulary)
	pos_vocabulary = j+"/pos_vocabulary"+j+".txt"
	neg_vocabulary = j+"/neg_vocabulary"+j+".txt"
	test = j+"/test"+j+".txt"
	accuracy = j+"/accuracy"+j+".txt"
	output = j+"/output"+j+".txt"
	vocab = open(vocabulary, "r");
	pos_vocab = open(pos_vocabulary, "r");
	neg_vocab = open(neg_vocabulary,"r");
	output_file = open(output,"w+");
	accuracy_file = open(accuracy,"w+");

	vocab_count = 0;
	neg_vocab_count = 0;
	pos_vocab_count = 0;

	with vocab as f:
	    vocab_count = sum(1 for _ in f)
	    #print (sum(1 for _ in f))

	with pos_vocab as f:
	    pos_vocab_count = sum(1 for _ in f)

	with neg_vocab as f:
	    neg_vocab_count = sum(1 for _ in f)

	print(vocab_count)
	print(neg_vocab_count)
	print(pos_vocab_count)

	probab_pos = 0.5
	probab_pos = math.log2(probab_pos)
	#print (probab_pos)

	probab_neg = 0.5
	probab_neg = math.log2(probab_neg)
	#print(probab_neg)

	
	#total_neg_probab = 0 

	#str1 = input("Enter word: ")
	f = open(test,"r")
	for linea in f:
		total_pos_probab = 0
		total_neg_probab = 0
		linea = linea[2:]
		for word in linea.split():
			word_count = ""
			with open(pos_vocabulary) as posfile:
			    for line in posfile:
			        if word in line:
			        	word_count  = line

			if (word_count == ""):
				count = 0;
			else:	
				count = word_count[16:] 
				count = int(count)
			#print(count)
			
			pos_probab = (count + 1) / (pos_vocab_count + vocab_count)
			pos_probab = math.log2(pos_probab) 
			#print (pos_probab)
			total_pos_probab = total_pos_probab + pos_probab
			
		#print(total_pos_probab)  

		for word in linea.split():
			word_count = ""
			with open(neg_vocabulary) as posfile:
			    for line in posfile:
			        if word in line:
			        	word_count  = line

			if(word_count == ""):
				count = 0;
			else:	
				count = word_count[16:] 
				count = int(count)

			neg_probab = (count + 1) / (neg_vocab_count + vocab_count)
			neg_probab = math.log2(neg_probab) 
			#print (pos_probab)
			total_neg_probab = total_neg_probab + neg_probab
			
		#print(total_neg_probab)

		total_pos_probab = total_pos_probab + probab_pos;
		total_neg_probab = total_neg_probab + probab_neg;

		if (total_pos_probab >= total_neg_probab):
			sentiment = "+"
		else:
			sentiment = "-"

		output_file.write(sentiment + "\n")
		
	output_file.close()

	file1 = open(output, "r")
	file2 = open(test, "r")
	for line1,line2 in list(zip(file2,file1)):
		line1 = line1[0]
		line2 = line2[0]
		if (line1 == line2):
			accuracy_file.write("1" + "\n")
		else:
			accuracy_file.write("0" + "\n")		