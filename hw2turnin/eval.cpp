#include "Map.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;

int evaluate(string infix, const Map& values, string& postfix, int& result) {
// Evaluates an integer arithmetic expression
    int openbrak=0,closebrak=0;
    string nospace;
    for(int m = 0; m < infix.size(); m++) {
        if (infix[m] != ' ')
            nospace+=infix[m];
    }
    
    infix = nospace;
    postfix = "";
    if (infix == "")
        return 1;
    stack<char>operatorStack;
    for (int i = 0; i < infix.size(); i++) {
         if (islower(infix[i])) {
            if (i+1 != infix.size() && (infix[i+1] == '(' || islower(infix[i+1])))
                return 1;
            postfix += infix[i];
        }
        if (infix[i] == '(') {
            openbrak++;
            if ((i+1) == infix.size() || infix[i+1] == ')'  || infix[i+1] == '+' || infix[i+1] == '-' || infix[i+1] == '/' || infix[i+1] == '*') {
                return 1;
            }
            operatorStack.push(infix[i]);
        }
        if (infix[i] == ')') {
            closebrak++;
            if (i+1!= infix.size() && (infix[i+1] == '(' || islower(infix[i+1])))
                return 1;
            while (operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        //get precendence of char you have, keep checking precedence of each one in stack
        //as long as precedence of that one is >= one you have, pop them off into potfix
        bool as = false;
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*') {
            while (!operatorStack.empty() && operatorStack.top()!= '(' && (infix[i] == '-' || infix[i] == '+')) {
                as = true;
                postfix += operatorStack.top();
                operatorStack.pop();

            }
            
            while (as==false && !operatorStack.empty() && operatorStack.top()!= '(' && (infix[i] == '*' || infix[i] == '/') && operatorStack.top()!= '+' && operatorStack.top()!= '-') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            
            operatorStack.push(infix[i]);
        }
        if(!islower(infix[i]) && infix[i] != '+' && infix[i] != '-' && infix[i] != '/' && infix[i] != '*' && infix[i] != ' ' && infix[i] != '(' && infix[i] != ')') {
            return 1;
        
        }
    }
    
    
    if(openbrak != closebrak)
        return 1;
    
    while(!operatorStack.empty()) {
        if(operatorStack.top() == '(' || operatorStack.top() == ')') return 1;
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    
    if(postfix.size() == 2)
        return 1;
    int op=0,num=0;
    for (int k = 0; k <postfix.size(); k++) {
        if (islower(postfix[k]))
            num++;
        else op++;
    }
    if (op>=num)
        return 1;
    
    int finalres;
    stack<int>operandStack;
    for (int j =0; j<postfix.size(); j++) {
        if (islower(postfix[j])) {
            int val;
            if (!values.get(postfix[j], val))
                return 2;
            operandStack.push(val);
        }
        else {
            char operand2 = operandStack.top();
            operandStack.pop();
            char operand1 = operandStack.top();
            operandStack.pop();
            if (postfix[j] == '+') {
                finalres = operand1 + operand2;
                operandStack.push(finalres);
            }
            if (postfix[j] == '-') {
                finalres = operand1 - operand2;
                operandStack.push(finalres);
            }
            if (postfix[j] == '*') {
                finalres = operand1 * operand2;
                operandStack.push(finalres);
            }
            if (postfix[j] == '/' && operand2 != 0) {
                finalres = operand1 / operand2;
                operandStack.push(finalres);
            }
            if (postfix[j] == '/' && operand2 == 0) {
                return 3;
            }
        }
    }
    result = operandStack.top();
    return 0;
}


int main()
       {
           char vars[] = { 'a', 'e', 'i', 'o', 'u', 'y', '#' };
           int  vals[] = {  3,  -9,   6,   2,   4,   1  };
           Map m;
           for (int k = 0; vars[k] != '#'; k++)
               m.insert(vars[k], vals[k]);
           string pf;
           int answer;
           assert(evaluate("a+ e", m, pf, answer)== 0  && pf == "ae+"  &&  answer == -6);
           answer = 999;
           assert(evaluate("", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("a+", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("a i", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("ai", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("()", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("()o", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("y(o+u)", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("y(*o)", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("a+E", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("(a+(i-o)", m, pf, answer) == 1  &&  answer == 999);
             // unary operators not allowed:
           assert(evaluate("-a--", m, pf, answer) == 1  &&  answer == 999);
           assert(evaluate("a*b", m, pf, answer) == 2  &&
                                   pf == "ab*"  &&  answer == 999);
           assert(evaluate("y +o *(   a-u)  ", m, pf, answer) == 0  &&
                                  pf == "yoau-*+"  &&  answer == -1);
           answer = 999;
           assert(evaluate("o/(y-y)", m, pf, answer) == 3  &&
                                   pf == "oyy-/"  &&  answer == 999);
           assert(evaluate(" a  ", m, pf, answer) == 0  &&
                                   pf == "a"  &&  answer == 3);
           assert(evaluate("((a))", m, pf, answer) == 0  &&
                                   pf == "a"  &&  answer == 3);
           assert(evaluate("e*i*(a+e)",m,pf,answer) == 0 && answer ==324);
           assert(evaluate("a*e*i+(a)",m,pf,answer) == 0 && pf == "ae*i*a+");
           assert(evaluate("a*e-i*a",m,pf,answer) == 0 && pf == "ae*ia*-");
           assert(evaluate("(a+e)",m,pf,answer)==0 && pf == "ae+");
           cout << "Passed all tests" << endl;
    }

