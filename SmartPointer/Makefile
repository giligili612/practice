out: Document.cpp main.cpp
	g++ $^ -o $@ -g -O1 -fsanitize=address -fno-omit-frame-pointer

clean:
	rm out
