//
//  expression.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/4/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

/*
 expr ::= int | ‘(‘ op expr… ‘)’;
 op ::= ‘+’ | ‘*’;
Examples:
 “( * 1 ( + 1 2 3 ) )” => 6
 “( * ( + 1 1 ) 17 )” => 34
 “7” => 7
 ( * ( + 1 1 ) 17 ) )
 ( * 17 ( + 1 1 ) )
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
#include <assert.h>

enum TYPE{OPERATOR, OPERAND, OPEN, CLOSE};
const char* DELIMITERS = " \t\r\n";

//check type of token s
TYPE TokenType(const string& s)
{
    if(s=="*" || s=="+")
        return OPERATOR;
    else if(s=="(")
        return OPEN;
    else if(s==")")
        return CLOSE;
    else
        return OPERAND;
}

//empty, single int, invalid expr

//Tokenize the input exprssion
vector<string> tokenizer(char* expr)
{
    vector<string> res;
    char* token = strtok(expr, DELIMITERS);
    while(token)
    {
        res.push_back(token);
        token = strtok(0, DELIMITERS);
    }
    return res;
}

int calculate(const string& op, const vector<int>& operands)
{
    if(op=="+")
    {
        int result = 0;
        for(int o : operands)
            result += o;
        return result;
    }
    else
    {
        int result = 1;
        for(int o : operands)
            result *= o;
        return result;
    }
}

//consume a valid expression starting from tokens[index] and return its result.
//index is updated after the calculation.
int func(const vector<string>& tokens, int& index)
{
    assert(index < tokens.size());
    
    string token = tokens[index++];
    switch(TokenType(token))
    {
        case OPERAND:
            return atoi(token.c_str());
        case OPEN:
            return func(tokens, index);
        case OPERATOR:
            vector<int> operands;
            while(TokenType(tokens[index]) != CLOSE)
                operands.push_back(func(tokens, index));
            index++;
            return calculate(token, operands);
    }
    assert(false);
    return 0;
}

int mainExp()
{
    char expr[] = "( * 1 ( + 1 2 3 ) )";
    vector<string> tokens = tokenizer(expr);
    int index = 0;
    cout << func(tokens, index) << endl;

    return 0;
}
