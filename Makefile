all: shell server

shell: shell.c
	gcc shell.c -o shell

server: server.c
	gcc server.c -o server

.PHONY :clean all

clean:
	rm -f *.o shell server