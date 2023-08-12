# Logical operators, using lists

#from cs50 import get_string

# Prompt user to agree
#s = get_string("Do you agree? ")

# Check whether agreed
#if s.lower() in ["y", "yes"]:
#    print("Agreed.")
#elif s.lower() in ["n", "no"]:
#    print("Not agreed.")
#-------------------------------------------
#simplified version
# Logical operators, using lists

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

s = s.lower()

# Check whether agreed
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")