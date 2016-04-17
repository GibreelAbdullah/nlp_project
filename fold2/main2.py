import math

for i in range(0,10):
	j=str(i)
	uni_vocabulary = j+"/uni_vocabulary"+j+".txt"
	bi_vocabulary = j+"/bi_vocabulary"+j+".txt"
	print (uni_vocabulary)
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

	flag = 1
	current_bi_flag = -1

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
			word = line[32:]
			word1 = int(word)
			uni_pos_vocab_count = uni_pos_vocab_count + word1

	with open(bi_pos_vocabulary) as f:
		for line in f:
			word = line[32:]
			word1 = int(word)
			bi_pos_vocab_count = bi_pos_vocab_count + word1

	with open(uni_neg_vocabulary) as f:
		for line in f:
			word = line[32:]
			word1 = int(word)
			uni_neg_vocab_count = uni_neg_vocab_count + word1

	with open(bi_neg_vocabulary) as f:
		for line in f:
			word = line[32:]
			word1 = int(word)
			bi_neg_vocab_count = bi_neg_vocab_count + word1		

	total_pos_vocab_count = uni_pos_vocab_count + bi_pos_vocab_count
	total_neg_vocab_count = uni_neg_vocab_count + bi_neg_vocab_count

	print(total_vocab_count)
	print(total_neg_vocab_count)
	print(total_pos_vocab_count)

	probab_pos = 0.5
	probab_pos = math.log10(probab_pos)
	#print (probab_pos)

	probab_neg = 0.5
	probab_neg = math.log10(probab_neg)
	#print(probab_neg)

	
	#total_neg_probab = 0 

	#str1 = input("Enter word: ")
	f = open(test,"r")
	for linea in f:
		total_pos_probab = 0
		total_neg_probab = 0
		current_bi_flag_pos = 1
		current_bi_flag_neg = 1
		linea = linea[4:]
		#print(linea)
		prevword = "*"
		prevword1 = "*"
		for word in linea.split():
			word_count = ""
			word1 = ""
			word2 = ""
			str1 = prevword + "," + word
			flag = 1
			#print("this : " + word)
			#print(str1)
			with open(bi_pos_vocabulary) as posfile:
				for line in posfile:
					if str1 in line:
						word_count = line

			#print(word_count)			

			if(word_count == "") and (current_bi_flag_pos == -1):
				word1 = prevword + " "
				word2 = word + " "
				current_bi_flag_pos = -1
				flag = 0

				with open(uni_pos_vocabulary) as posfile:
					for line in posfile:
						if word1 in line:
							word_count = line
			else:
				if(word_count == ""):
					current_bi_flag_pos = -1
					flag = 1
				else:
					current_bi_flag_pos = 1
					flag = 0	

			if (word_count == ""):
				count = 0
			else :
				count = int(word_count[32:])
			
			if(flag == 0):
				pos_probab = (count + 1) / (total_pos_vocab_count + total_vocab_count)
				pos_probab = math.log10(pos_probab) 
				#print (pos_probab)
				total_pos_probab = total_pos_probab + pos_probab
				#print(total_pos_probab)
				#print(count)
				#print(total_pos_probab)

			prevword = word  
		#print(linea)	

		for word in linea.split():
			word_count = ""
			word1 = ""
			word2 = ""
			str1 = prevword1 + "," + word
			flag = 1

			with open(bi_neg_vocabulary) as negfile:
				for line in negfile:
					if str1 in line:
						word_count = line				

			if(word_count == "") and (current_bi_flag_neg == -1):
				word1 = prevword1 + " "
				word2 = word + " "
				current_bi_flag_neg = -1
				flag = 0

				with open(uni_neg_vocabulary) as negfile:
					for line in negfile:
						if word1 in line:
							word_count = line

			else:
				if(word_count == ""):
					current_bi_flag_neg = -1
					flag = 1
				else:
					current_bi_flag_neg = 1
					flag = 0


			if (word_count == ""):
				count = 0
			else :
				count = int(word_count[32:])

			if(flag == 0):
				neg_probab = (count + 1) / (total_neg_vocab_count + total_vocab_count)
				neg_probab = math.log10(neg_probab) 
				#print (pos_probab)
				total_neg_probab = total_neg_probab + neg_probab
				#print(total_neg_probab)
				#print(count)

			prevword1 = word

		total_pos_probab = total_pos_probab + probab_pos;
		total_neg_probab = total_neg_probab + probab_neg;
		word_pos_1 = str(total_pos_probab)
		word_neg_1 = str(total_neg_probab)


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