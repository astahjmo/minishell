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
state | '<' | '>' | '>>' | '<<' | '||' | '&&' | '|' | '&' | WORD
0     | 1   |  2  | 3    | 4    | -1   | -1   | -1  | -1  | 5  
1     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 5 
2     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 5 
3     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 5 
4     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 5 
5     | 1   | 2   |  3   |  4   | 6    |  7   |  8  | 9   | 5
6     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 5
7     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 5
8     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 5
9     | -1  | -1  | -1   | -1   | -1   | -1   | -1  | -1  | 5
```
