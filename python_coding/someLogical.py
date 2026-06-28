user_input = input("Enter a number: ")

try:
    # Try to convert the input to an integer
    num = int(user_input)
    print("Your number is:", num)
except ValueError:
    # If it fails, this block runs instead of crashing
    print("Please enter a numeric value.")