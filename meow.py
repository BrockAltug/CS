#Code written in C
#// Demonstrates while loop
#
#include <stdio.h>
#
#int main(void)
#{
#    int i = 0;
#    while (i < 3)
#   {
#        printf("meow\n");
#        i++;
#    }
#}
#-----------------------------------
#Same code written in Python
# Demonstrates while loop

i = 0
while i < 3:
    print("meow")
    i += 1
#-----------------------------------
# Better design

for i in range(3):
    print("meow")
#-----------------------------------
#Improvements
# Abstraction

def main():
    for i in range(3):
        meow()

# Meow once
def meow():
    print("meow")


main()
#-----------------------------------
# Abstraction with parameterization

def main():
    meow(3)


# Meow some number of times
def meow(n):
    for i in range(n):
        print("meow")


main()