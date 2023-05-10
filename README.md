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
state | '<<' | '>>' | '||' | '&&' | '|' | '&' | '<' | '>' | WORD
0     | 0    |  1   | 2    | 3    | -1  | -1  | -1  | -1  | 8
1     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 8
2     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 8
3     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 8
4     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 8
5     | 0    | 1    |  2   |  3   | 4   |  5  |  6  | 7   | 8
6     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 8
7     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 8
8     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 8
9     | -1   | -1   | -1   | -1   | -1  | -1  | -1  | -1  | 8
```
