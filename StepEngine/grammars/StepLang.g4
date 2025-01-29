grammar StepLang;

program: (function)* main;
main: body '\n'?;
function: header '=' body '\n';
header: IDENTIFIER ('(' variable_list ')')?;
body: (statement)+;
statement: ACTION
         | loop
         | invocation;
variable_list: (IDENTIFIER ',')* IDENTIFIER;
invocation : IDENTIFIER ('(' expression_list ')')?;
expression_list : (expression ',')* expression;
loop : '<' condition=expression '>' '[' body ']';
expression: IDENTIFIER
          | NUMBER
          | expression OPERATOR expression
          | '(' expression ')';
ACTION: [alr];
IDENTIFIER: [a-z];
OPERATOR: MUL | DIV | ADD | SUB;
MUL: '*';
DIV: '/';
ADD: '+';
SUB: '-';
NUMBER: [0-9]+;
WHITESPACE : [ \t]+ -> skip;
//SEP: ',' -> skip;