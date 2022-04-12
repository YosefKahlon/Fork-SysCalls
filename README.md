# Fork-SysCalls
ID: 209011840 
ID: 206795841


This project represent a command line in linux

Here is the instruction of how to use:

- Before you start

<div dir='ltr'>

    make all
    ./shell
    ./server
</div>


1. EXIT - exit from the shell.
2. ECHO - print to standard output the text after ECHO (ECHO HAIDE MACCABI YAFO -->  HAIDE MACCABI YAFO).
3. TCP PORT - open TCP connection with a server, standard output will be copied to the server.
4. LOCAL - standard output return to shell, close the TCP socket.
5. DIR - show all fill in the current directory.
6. CD - change the library to the library after the command (CD KABILIO --> /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/KABILIO).
7. COPY SRC DEST - copy the src file into dest file (COPY src.txt dest.txt).
8. DELETE FILENAME - delete file from the library (DELETE dest.txt).
9. Every other command will handle twice, by the system and fork child. 
  
 
