run: run_lower run_stopword run_test_training run_super_doc run_unigram run_bigram run_vocabulary run_main run_accuracy clean

lower: 1_to_lower.cpp
	g++ -o $@ $^

stopword: 2_remove_stopwords.cpp
	g++ -o $@ $^

test_training: 3_test_training.cpp
	g++ -o $@ $^

super_doc: 4_super_doc.cpp
	g++ -o $@ $^

unigram: 5_unigram.cpp
	g++ -o $@ $^

bigram: 6_bigram.cpp
	g++ -o $@ $^

vocabulary: 7_vocabulary.cpp
	g++ -o $@ $^

run_lower: lower
	./lower

run_stopword: stopword
	./stopword

run_test_training: test_training
	./test_training

run_super_doc: super_doc
	./super_doc

run_unigram: unigram
	./unigram

run_bigram: bigram
	./bigram

run_vocabulary: vocabulary
	./vocabulary

run_main: main2.py
	python3.4 $^

run_accuracy: accuracy.py
	python3.4 $^

clean:  
	rm -f lower stopword test_training super_doc vocab