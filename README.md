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
state | '<' | '>' | '<<' | '>>' | '||' | '&&' | '|' | '&' | WORD
0     | 1   |  2  | 3    | 4    | -1   | -1   | -1  | -1  | 9  
1     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 9 
2     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 9 
3     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 9 
4     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 9 
5     | 1   | 2   |  3   |  4   | 5    |  6   |  7  | 8   | 9
6     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 9
7     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 9
8     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 9
9     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 9
```
