FILES=testzxcvbn testzxcvbn_san testzxcvbn_LF testzxcvbn_AFL

all: $(FILES)

clean:
	rm -rf $(FILES)

testzxcvbn: TestZxcvbn.cpp
	clang++ -o testzxcvbn TestZxcvbn.cpp -ldeepstate libzxcvbn.a

testzxcvbn_san: TestZxcvbn.cpp
	clang++ -o testzxcvbn_san TestZxcvbn.cpp -ldeepstate libzxcvbn_san.a -fsanitize=address,undefined

testzxcvbn_LF: TestZxcvbn.cpp
	clang++ -o testzxcvbn_LF TestZxcvbn.cpp -ldeepstate_LF libzxcvbn_LF.a -fsanitize=fuzzer

testzxcvbn_AFL: TestZxcvbn.cpp
	afl-clang++ -o testzxcvbn_AFL TestZxcvbn.cpp -ldeepstate_AFL libzxcvbn_AFL.a
