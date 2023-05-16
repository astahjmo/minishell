# Minishell

the minishell project is about making a shell with some 
bash features

the bnf notation:
```bnf
<Command> ::= [<Redirection>] <Word> <Argument>* | (<Command> (<Redirection> | <Logics> | <Pipe>) <Command>)
<Pipe> ::= '|' 
<Logics> ::=  '&&' | '||'
<Redirection> ::= '<' | '<<' | '>>' | '>'
<Argument> ::= (['-' | '--'] <Word>)+
<Word> ::= <File> | <String>
```

machine state:

```
         1      2      3      4      5     6     7     8     9
state | '<<' | '>>' | '||' | '&&' | '|' | '&' | '<' | '>' | WORD
0     |  1   |  2   | -1   | -1   | -1  | -1  |  7  |  8  | 9
1     |  9   | -1   | -1   | -1   | -1  | -1  |  -1 | -1  | 9
2     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 9
3     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 9
4     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 9
5     | -1   |  9   | -1   | -1   | -1  | -1  |  9  |  9  | 9
6     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 9
7     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 9
8     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 9
9     |  1   |  2   |  3   |  4   |  5  |  6  | 7   | 8   | 9
```
## TODO

- [x] Display a prompt when waiting for a new command

- [x] Have a working history

- [x] Not use more than one global variable. Think about it. You will have to explain its purpose

- [x] Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).

- [x] Handle ’ (single quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence.

- [x] ctrl-C displays a new prompt on a new line.

- [x] ctrl-D exits the shell.

- [x] ctrl-\ does nothing.

- [ ] Search and launch the right executable (based on the PATH variable or using a relative or an absolute path

- [ ] Handle " (double quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence except for $ (dollar sign).

### Implement redirections:

- [ ] Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.

- [ ] Handle environment variables ($ followed by a sequence of characters) which should expand to their values.

### Your shell must implement the following builtins:

- [ ] echo with option -n

- [ ] cd with only a relative or absolute path

- [ ] pwd with no options

- [ ] export with no options

- [ ] unset with no options

- [ ] env with no options or arguments

- [ ] exit with no options