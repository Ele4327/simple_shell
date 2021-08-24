shelling_ :
	gcc -g  -Wall -Werror -Wextra -pedantic -std=gnu89 main.c -o hsh

comp-holb- :
	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c -o hsh

comp-holb_ :
	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh

chown :
	sudo chown dkbarb10 *

clean :
	rm -f shelling_ *.o *.gch *.out *hsh

clean_tops :
	rm -rf *.tmp .*simple_shell_history

run :
	sudo cp hsh /usr/local/sbin; ./hsh

running :
	./a.out ls /etc

shellingR :
	./_shelling

valgrind :
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./hsh