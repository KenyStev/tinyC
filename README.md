# tinyC
Compiler II Class - Project at Unitec San Pedro Sula, Honduras

tinyC accept a reduced part of **c programming language** which is described right here, and compile it to Assembly MIPS32

## Getting Started

### Requirements

- [g++](https://gcc.gnu.org/)
- [flex](https://github.com/westes/flex)
- [bison](https://www.gnu.org/software/bison/)
- [make](https://www.gnu.org/software/make/)

### Try Me!

```
    $ git clone https://github.com/KenyStev/tinyC
    $ cd tinyC
    $ make
    $ ./tinyC <source-file-path>
```

### Build

```
    $ make
```

### Clean

```
    $ make clean
```

### Supported Types
* int
* char
* pointer - one level
* arrays - unidimensional

### Arithmetic Expressions
* '+' 	= Sum
* '++' 	= Increment						INC_OP
* '-' 	= Sub
* '--' 	= Decrement						DEC_OP
* '*' 	= Mult
* '/' 	= Div
* '%' 	= Mod

### Logical Expressions
* '&&' 	= And							AND_OP
* '||' 	= Or							OR_OP
* '!' 	= Not
* '? :' = Ternary

### Bits Expressions
* '&' 	= And
* '|' 	= Or
* '^' 	= Xor
* '~' 	= Not
* '>>' 	= Shift Right Logical			RIGHT_OP
* '<<' 	= Shift Left Logical			LEFT_OP

### Relational Operators
* '>'	= Greater than
* '<'	= Less than
* '>='	= Greater or Equal than			GE_OP
* '<='	= Less or Equal than			LE_OP
* '=='	= Equal than					EQ_OP
* '!='	= Not Equal than				NE_OP

### Assign Expressions
* '='
* '>>='	= Shift Right Logical Assign	RIGHT_ASSIGN
* '<<=' = Shift Left Logical Assign		LEFT_ASSING
* '+='	= Add Assign					ADD_ASSIGN
* '-='	= Sub Assign					SUB_ASSIGN
* '*='	= Mult Assign					MULT_ASSIGN
* '/='	= Div Assign					DIV_ASSIGN
* '%='	= Mod Assign					MOD_ASSIGN
* '&='	= And Assign					AND_ASSIGN
* '^='	= Xor Assign					XOR_ASSIGN
* '|='	= Or Assign						OR_ASSIGN

### Access Memory
* '&' = Get Memory Address
* '*' = Disreference Pointer

### Control Structures
- `if (expression) '{'? Statements '}'? {else Statements}?`
- `for (expression; expression; expression) '{'? Statements '}'?`
- `while (expression) '{'? Statements '}'?`
- `do'{'? Statements '}'? while (expression) ;`
- functions declaration and call functions

### Keywords
| Keyword	| Token			|
|-----------|---------------|
| break		| BREAK_KW		|
| char		| CHAR_KW		|
| continue	| CONTINUE_KW	|
| do		| DO_KW			|
| else		| ELSE_KW		|
| for		| FOR_KW		|
| if		| IF_KW			|
| int		| INT_KW		|
| return	| RETURN_KW		|
| sizeof	| SIZEOF_KW		|
| void		| VOID_KW		|
| while		| WHILE_KW		|

## Credits

tinyC is mainly developed by Kevin Javier Estevez (kjestevez dot 0795 at gmail dot com)

## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE V3 - see the [LICENSE](https://github.com/KenyStev/tinyC/blob/master/LICENSE) file for details.