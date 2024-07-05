Purpose of the project was to create a number sorting algorithm. 

As a summary from the subject:
"You have at your disposal a set of integer values, 2 stacks, and a set of instructions
to manipulate both stacks. 

You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time."

The argument must fit in an integer.

This is one of my favourite projects in my coding career so far. Writing algorithm was tricky but interesting. One again I did not have a very clear plan in the begining. 
I saw like 30sec long video about algorithm called chunks which had a couple of lines of instructions: "For a 100, find the 20 smallest values in stack.a, and push into stack.b.
Then find the next 20 smallest values that remain in stack.a, until stack.a is empty.
Then, find the biggest value in stack b by rotate or reverse-rotate, and push it back into stack.a.
For a 500, change the chunk size to 70, more or less.". Quite loose instructions so my implementation was not very efficent and I started to add some optimization to it. Most people from my cohort choose the "turk algorithm which is one of the most efficent ones." 

The algorithm sorts 100 numbers in less than 700 moves which is condidered as efficent. For 500 numbers it is around 5 500 - 5900 moves. To get the full points there should be no case over 5 500. Some algorithms got it easily under 5 000 but I think this one is unique. 
The algorithm: 
The numbers are given their correct position (a sequence number) in the final stack. Basically the smallest has the number 1 and the biggest has the N (how many numbers we have in total).
Then the numbers are split in chunks according to their sequence number. So if the stack is over 200 numbers the denominator is (sife of list / 10) and if the stack is 200 or less the denominator is just 20. So for hundred numbers it will devide them in 20 chunks each size of 5 and for 200 size of 10 and for 500 numbers 50 chunks each size of 10 and so on. 
So, if we have 200 numbers in the first chunks we have the sequence 1-10. We start looking for these numbers from our stack. Let's say we find sequence 5 as the first one from that chunk. We check is it on the top 100 or the bottom 100 to determine do we need to rotate or reverse rotate (optimsation).
We will rotate and push that one to B. Now we keep looking for numbers from the same chunk. If the algo founds the sequence 1 it pushes it and then it looks for chunk 2 - 10. In B if the number we got is lower than the median of current chunk (lets say we hot sequence 1) we want to put it on bottom of B (optimisation).
This way when we start pushing numbers back to A we have the righ numbers closer. 
We keep doing this recursively until the list is under 6 and then we just keep pushing the smallest we fing (no more chunks) until there is only three and then use the hard coded algo to sort that. 
Now it is time to start pushing numbers from B to back to A. We just look for the correct sequence (starting from 4 and it should be on top) and calculate do we need to do rotation or reverse rotation first.

Thank you for reading. Might add something here later. 
