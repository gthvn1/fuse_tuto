main: main.c

fmt:
	clang-format -i main.c

clean:
	rm -f main
