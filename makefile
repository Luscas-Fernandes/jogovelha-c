bin_dir = binaries
src_dir = source
hea_dir = headers
src = main.c funcGame.c renderGame.c
hea = directives.h funcGame.h renderGame.h


objects: $(hea_dir)/directives.h $(hea_dir)/funcGame.h $(hea_dir)/renderGame.h
	mkdir -p $(bin_dir)
	cc -c $(src_dir)/funcGame.c -o $(bin_dir)/funcGame.o
	cc -c $(src_dir)/main.c -o $(bin_dir)/main.o
	cc -c $(src_dir)/renderGame.c -o $(bin_dir)/renderGame.o

compile: objects
	cc $(bin_dir)/main.o $(bin_dir)/funcGame.o $(bin_dir)/renderGame.o -o tictactoe

clean:
	rm -rf $(bin_dir)/*.o $(bin_dir) tictactoe