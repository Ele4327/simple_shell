![](https://github.com/Ele4327/printf/blob/main/img/Header.png)

👋 Hello Devs
# Simple Shell

Hello and Welcome to our Holberton Simple Shell project.
In this repository you will find our own simple shell, developed by software developers in progress.

For those who dont know a shell is a program that presents a command line interface which allows you to control your computer using commands entered with a keyboard instead of controlling graphical user interfaces (GUIs) with a mouse/keyboard combination.

For a more specific explanation, we invite you to see our manual: man_1_simple_shell

## Features

- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

List of allowed functions and system calls:

- [ ] access
- [ ] chdir
- [ ] close
- [ ] closedir
- [ ] execve
- [ ] exit
- [ ] _exit
- [ ] fflush
- [ ] fork
- [ ] free
- [ ] getcwd
- [ ] getline
- [ ] getpid
- [ ] isatty
- [ ] kill
- [ ] malloc
- [ ] open
- [ ] opendir
- [ ] perror
- [ ] read
- [ ] readdir
- [ ] signal
- [ ] stat (__xstat)
- [ ] lstat (__lxstat)
- [ ] fstat (__fxstat)
- [ ] strtok
- [ ] wait
- [ ] waitpid
- [ ] wait3
- [ ] wait4
- [ ] write


## Compilation and Execution
To run the program it is as simple as compiling it in the terminal with the following flags: 
> gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

If you wish, you can optimize this process by creating an alias in the terminal to summarize all the flags and steps in a single command (Note, in the following command you are also running the compiled program, and also proceed to delete the executable to leave the folder as clean as possible).

> alias cplpf="gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf ; ./printf ; rm ./printf"

## How this work:

First of all, if you want and need a Manual, to look at the specific commands, how they work, their flags, accepted parameters, qualities, and everything else you need, of course we have our own man _printf!

Just type in the console:
> man ./man_3_printf

### Main Function
> int _printf(const char *format, ...);

### Subfunctions
They are those that print to the standard output, according to the format specified in the % parameter.
All of these are stored in 'op-func' files.

So, for example: if the parameter is %c, then the program will look for the function "printf_c" and print a character.
```
int main (void)
{
	_printf("Character: [%c]\n", 'H')
}
```
The output will be:
>Character:[H]

And if the parameter is %s, then the program will look for the function "printf_s" and print a string.
```
int main (void)
{
	char *str = "I am a string !";
	_printf("String:[%s]\n", str);
}
```

The output will be:
>String:[I am a string !]

#### Correspondence table

| Function  | Symbol  | Description |
| :------ |:--------------:| ---------------------:|
| `printf_s`      | %s | Prints a string |
| `printf_c`      | %c  |   Prints a character |
| `printf_d`   | %d   |   Prints in decimal format |
| `printf_i`      |%i  |   Prints a integer |
| `printf_per`      | %per |   Prints in percentage format |
| `printf_bin`     | %bin |   Prints in binary type |
| `printf_o`      | %o |   Prints in octal type |
| `printf_x`      | %x |   Prints in hexadecimal format |
| `printf_u`     | %u |   Prints in unsigned decimal format |
| `printf_R`     | %R |   Prints in ROT13 format |
| `printf_r`     | %r |   Prints a string in reverse |
                
----

### Aux Functions:
They are those that allow the sub-functions to have an adequate behavior according to their needs.
##### Putchar:
Write a digit, using the write function (<unistd.h>).
> int _putchar(char c);
##### Strlen:
Measures the length of a string
> int _strlen(char *s);
##### Itoa:
Convert integers to strings
> char *_itoa(int i, char *strout, int base);
##### Print-Rev-Recursion:
Prints a string in reverse
> void _print_rev_recursion(char *s);

### Edge Cases

These are situations in which the code obtains unexpected results under certain specific conditions.
These conditions are usually abnormal, e.g. typing errors or grouping errors, but they must still be taken into account.

```
    _printf("1 -> %");
    _printf("\n");
    _printf("2 -> %\n");
    _printf("3 -> %%%\n");
    _printf("4 -> %%%%\n");
    _printf("5 -> %% %%\n");
    _printf("\n");
    _printf("6 -> %%%z\n");
    _printf("7 -> %% %z\n");
    _printf("8 -> %%%s\n", "HELLO");
```

### FlowChart
Image:

![](https://github.com/Ele4327/printf/blob/main/img/flow_chart.png)
                
----

<h3 align="left">Contribuitors</h3>
<p align="left">
<a href="https://twitter.com/@crisgrvc" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="@crisgrvc" height="30" width="40" />Cristian Granada</a>
</p>
<p align="left">
<a href="https://twitter.com/@CanelitaCadavid" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="@crisgrvc" height="30" width="40" />Laura Alejandra Cadavid</a>
</p>
<p align="left">
<a href="https://twitter.com/@ele5438" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="@crisgrvc" height="30" width="40" />Sebastian Garzón</a>
</p>

<h3 align="left">Languages and Tools:</h3>
<p align="left"> <a href="https://www.gnu.org/software/bash/" target="_blank"> <img src="https://www.vectorlogo.zone/logos/gnu_bash/gnu_bash-icon.svg" alt="bash" width="40" height="40"/> </a> <a href="https://www.cprogramming.com/" target="_blank"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> <a href="https://git-scm.com/" target="_blank"> <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/> </a> <a href="https://www.linux.org/" target="_blank"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/> </a> </p>


##### Thanks for your attention, feel free to contribute to the project or contact us if you need something

![](https://github.com/Ele4327/printf/blob/main/img/holb_logo.png)

### End