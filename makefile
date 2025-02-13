bin_dir = binaries
src_dir = source
hea_dir = headers
src = main.c funcGame.c renderGame.c
hea = directives.h funcGame.h renderGame.h


objects:
	mkdir -p $(bin_dir)
	cc -c $(src_dir)/funcGame.c -o $(bin_dir)/funcGame.o
	cc -c $(src_dir)/main.c -o $(bin_dir)/main.o
	cc -c $(src_dir)/renderGame.c -o $(bin_dir)/renderGame.o

compile: objects
	cc $(src_dir)/funcGame.c $(src_dir)/main.c $(src_dir)/renderGame.c -o tictactoe

clean:
	rm -rf $(bin_dir)/*.o $(bin_dir) tictactoe