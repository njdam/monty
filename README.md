# The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line.

## The monty program

1. Usage: `monty file`

=> where `file` is the path to the file containing Monty byte code

2. If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`.

3. If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file `<file>`, followed by a new line, and exit with the status `EXIT_FAILURE`

=> where `<file>` is the name of the file

4. If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`

=> where is the line number where the instruction appears.
=> Line numbers always start at 1

5. The monty program runs the bytecodes line by line and stop if either:

=> it executed properly every line of the file
=> it finds an error in the file
=> an error occured

6. If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.

7. You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …).

