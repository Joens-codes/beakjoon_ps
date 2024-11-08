from typing import Any


class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            raise IndexError("pop from empty stack")

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            raise IndexError("peek from empty stack")

    def size(self):
        return len(self.items)
    
    def clear(self):
        self.items = []

def precedence(op):
    if op =='(' or op == ')': return 0
    elif op =='+' or op =='-' : return 1
    elif op =='*' or op =='/' : return 2
    else : return -1
def Infix2postfix(expr):
    box = []
    s = Stack()
    for i in expr:
        if expr in '(':
            while(True):
                if( i  == ")"):
                    break
                if i in "+-*/":
                    s.push(i)
                    if precedence(expr[i]) < precedence(expr[i + 2]):
                        for i in s.items:
                            n = s.pop()
                            box.append(n)
                else:
                    box.append(expr[i])
        if expr[i] in "+-*/":
            s.push(expr[i])
            if precedence(expr[i]) < precedence(expr[i +2]):
                for i in s.items:
                    n = s.pop()
                    box.append(n)
        else:
            box.append(expr[i])
    return box

def evalPostfix(expr):
    s = Stack()
    for token in expr:
        if token in "+-*/":
            val2 = s.pop()
            val1 = s.pop()
            if(token == '+'): s.push(val1 + val2)
            elif(token == '-'): s.push(val1 - val2)
            elif(token == '*'): s.push(val1 * val2)
            elif(token == '/'): s.push(val1 / val2)
        else:
            s.push(float(token))
    return s.pop()



infix1 = ['8','/','2', '-', '3', '+', '(', '3', '*', '2', ')']
infix2 = ['1', '/', '2', '*', '(', '1', '/', '4', ')']
postfix1 = Infix2postfix(infix1)
postfix2 = Infix2postfix(infix2)
print(' 중위표기: ', infix1)
print(' 후의표기: ', postfix1)
result1 = evalPostfix(postfix1)
result2 = evalPostfix(postfix2)
print(' 중위표기: ', infix1)
print(' 후의표기: ', postfix1)
print(' 계산결과: ', result1, end='\n\n')
print(' 중위표기: ', infix2)
print(' 후의표기: ', postfix2)
print(' 계산결과: ', result2)