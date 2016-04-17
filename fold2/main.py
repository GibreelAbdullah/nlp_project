import math

for i in range(0,10):
	j=str(i)
	uni_vocabulary = j+"/uni_vocabulary"+j+".txt"
	bi_vocabulary = j+"/bi_vocabulary"+j+".txt"
	print (vocabulary)
	uni_pos_vocabulary = j+"/uni_pos_vocabulary"+j+".txt"
	uni_neg_vocabulary = j+"/uni_neg_vocabulary"+j+".txt"
	bi_pos_vocabulary = j+"/bi_pos_vocabulary"+j+".txt"
	bi_neg_vocabulary = j+"/bi_neg_vocabulary"+j+".txt"
	test = j+"/test"+j+".txt"
	accuracy = j+"/accuracy"+j+".txt"
	output = j+"/output"+j+".txt"
	uni_vocab = open(uni_vocabulary, "r");
	bi_vocab = open(bi_vocabulary, "r");
	uni_pos_vocab = open(uni_pos_vocabulary, "r");
	uni_neg_vocab = open(uni_neg_vocabulary,"r");
	bi_pos_vocab = open(bi_pos_vocabulary, "r");
	bi_neg_vocab = open(bi_neg_vocabulary,"r");
	output_file = open(output,"w+");
	accuracy_file = open(accuracy,"w+");

	uni_vocab_count = 0;
	uni_neg_vocab_count = 0;
	uni_pos_vocab_count = 0;
	bi_vocab_count = 0;
	bi_neg_vocab_count = 0;
	bi_pos_vocab_count = 0;

	with uni_vocab as f:
	    uni_vocab_count = sum(1 for _ in f)
	    #print (sum(1 for _ in f))

	with bi_vocab as f:
	    bi_vocab_count = sum(1 for _ in f)
	#with pos_vocab as f:
	 #   pos_vocab_count = sum(1 for _ in f)

#	with neg_vocab as f:
#	    neg_vocab_count = sum(1 for _ in f)
	
	total_vocab_count = uni_vocab_count + bi_vocab_count

	with open(uni_pos_vocabulary) as f:
		for line in f:
			word = line[16:]
			word1 = int(word)
			uni_pos_vocab_count = uni_pos_vocab_count + word1

	with open(bi_pos_vocabulary) as f:
		for line in f:
			word = line[16:]
			word1 = int(word)
			bi_pos_vocab_count = bi_pos_vocab_count + word1

	with open(uni_neg_vocabulary) as f:
		for line in f:
			word = line[16:]
			word1 = int(word)
			uni_neg_vocab_count = uni_neg_vocab_count + word1

	with open(bi_neg_vocabulary) as f:
		for line in f:
			word = line[16:]
			word1 = int(word)
			bi_neg_vocab_count = bi_neg_vocab_count + word1		

	total_pos_vocab_count = uni_pos_vocab_count + bi_pos_vocab_count		
	#pos_vocab_count = pos_vocab_count - 270
	#neg_vocab_count = neg_vocab_count - 270
	total_neg_vocab_count = uni_neg_vocab_count + bi_neg_vocab_count

	print(total_vocab_count)
	print(total_neg_vocab_count)
	print(total_pos_vocab_count)

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
		linea = linea[4:]
		for word in linea.split():
			word_count = ""
			prevword = "*"
			word1 = ""
			word2 = ""
			str1 = prevword + "," + word
			with open(bi_pos_vocabulary) as posfile:
				for line in posfile:
					if str1 in line:
						word_count = line

			if(word_count == ""):
				word1 = prevword
				word2 = word

				if(prevword == "*"):
					with open(uni_pos_vocabulary) as posfile:
						for line in posfile:
							if word2 in line:
								word_count = line

				else:
					with open(uni_pos_vocabulary) as posfile:
						for line in posfile:
							if word1 in line:
								word_count = line

			if (word_count == ""):
				count = 0
			else :
				count = word_count[16:]
				
			
			pos_probab = (count + 1) / (total_pos_vocab_count + total_vocab_count)
			pos_probab = math.log2(pos_probab) 
			#print (pos_probab)
			total_pos_probab = total_pos_probab + pos_probab
			
		#print(total_pos_probab)  

		for word in linea.split():
			word_count = ""
			prevword = "*"
			word1 = ""
			word2 = ""
			str1 = prevword + "," + word
			with open(bi_neg_vocabulary) as negfile:
				for line in negfile:
					if str1 in line:
						word_count = line

			if(word_count == ""):
				word1 = prevword
				word2 = word

				if(prevword == "*"):
					with open(uni_neg_vocabulary) as negfile:
						for line in negfile:
							if word2 in line:
								word_count = line

				else:
					with open(uni_neg_vocabulary) as negfile:
						for line in negfile:
							if word1 in line:
								word_count = line

			if (word_count == ""):
				count = 0
			else :
				count = word_count[16:]

			neg_probab = (count + 1) / (total_neg_vocab_count + total_vocab_count)
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