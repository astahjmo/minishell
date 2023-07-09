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

- [x] ctrl-C displays a new prompt on a new line.

- [x] ctrl-D exits the shell.

- [x] ctrl-\ does nothing.

- [x] Handle $? which should expand to the exit status of the most recently executed foreground pipeline.

- [x] Handle environment variables ($ followed by a sequence of characters) which should expand to their values.

- [x] Handle ’ (single quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence.

- [x] Handle " (double quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence except for $ (dollar sign).

- [ ] Search and launch the right executable (based on the PATH variable or using a relative or an absolute path

- [ ]  < should redirect input.

- [ ]  > should redirect output.

- [x] << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!

- [ ] >> should redirect output in append mode.

- [ ] Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.

### Your shell must implement the following builtins:

- [x] echo with option -n

- [x] cd with only a relative or absolute path

- [x] pwd with no options

- [x] export with no options

- [x] unset with no options

- [x] env with no options or arguments

- [x] exit with no options

### PROBLEMS

- [x] PODE SER INPUT E OUTPUT 

- [x?] Exit after export leaks

- [ ] Finish interpolation

- [ ] Make redirections work with child processes

- [ ] Heredoc doesn't close

- [ ] Heredoc doesn't break after SIGINT
