from cs50 import get_int

n = 0

# Get user input for pyramid hight
while (n < 1 or n > 8):
    n = get_int("Height: ")

# Print the pyramid
for col in range(n):
    # Printing pyramid 1
    for space in range(n - col - 1):
        print(" ", end="")
    for hash in range(col + 1):
        print("#", end="")
    # Printing space inbetween
    print("  ", end="")
    # Printing pyramid 2
    for hash2 in range(col + 1):
        print("#", end="")
    print()

