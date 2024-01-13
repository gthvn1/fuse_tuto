CFLAGS=`pkg-config fuse3 --cflags --libs`

main: main.c
	$(CC) -Wall $^ $(CFLAGS) -o $@

fmt:
	clang-format -i main.c

clean:
	rm -f main
