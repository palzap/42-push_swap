# Push_swap

## Overview
The push_swap project at 42 is a sorting algorithm project that requires you to write two programs in C: push_swap and checker. The goal of the project is to sort a stack of integers using only two stacks (named a and b) and a set of predefined operations. The program push_swap takes a list of integers as input, sorts the integers using the defined operations, and outputs a list of operations that can be used to sort the stack. The program checker takes a list of integers and a list of operations as input, applies the operations to the stack, and outputs either "OK" or "KO" depending on whether or not the stack is sorted after applying the operations.

The set of predefined operations includes:

* sa : swap the first two elements of stack a
* sb : swap the first two elements of stack b
* ss : do sa and sb simultaneously
* pa : move the first element from stack b to stack a
* pb : move the first element from stack a to stack b
* ra : rotate the stack a (move the first element to the end of the stack)
* rb : rotate the stack b (move the first element to the end of the stack)
* rr : do ra and rb simultaneously
* rra : reverse rotate the stack a (move the last element to the top of the stack)
* rrb : reverse rotate the stack b (move the last element to the top of the stack)
* rrr : do rra and rrb simultaneously

The project requires you to implement an efficient algorithm that can sort the stack of integers using the smallest number of operations possible. The project is designed to test your understanding of algorithms and data structures, as well as your ability to write clean, efficient, and well-organized code.

## Evaluation
#### First submission
06/02/2023  
0%  

#### Second submission
13/02/2023  
125%
