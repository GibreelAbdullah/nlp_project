import math

readme = open("readme.txt","w+")
total_count = 0

for i in range(0,10):
	j = str(i)
	accuracy = j+"/accuracy"+j+".txt"
	accuracy1 = open(accuracy,"r")
    
	count = 0;

	for line in accuracy1:
		line = line[0]
		if (line == "1"):
			count = count + 1;

	print(count)
	total_count = total_count + count;
	accuracy_percentage = (count / 60) * 100
	accuracy_percentage_str = str(accuracy_percentage)
	readme.write(accuracy_percentage_str)
	readme.write("\n")

print(total_count)
final_accuracy_percentage = (total_count / 600) * 100
final_accuracy_percentage = str(final_accuracy_percentage)
readme.write("Total accuracy: ")
readme.write(final_accuracy_percentage)	
readme.close()		
