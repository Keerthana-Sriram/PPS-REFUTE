def is_armstrong_number(number):
    """Function to check if a number is Armstrong number."""
    try:
        # Convert the number to a string to get the number of digits
        str_num = str(number)
        num_digits = len(str_num)
        
        # Calculate the sum of digits raised to the power of the number of digits
        armstrong_sum = 0
        for digit in str_num:
            armstrong_sum += int(digit) ** num_digits
        
        # Check if the sum is equal to the original number
        return armstrong_sum == number
    except OverflowError:
        print("Overflow occurred during calculation!")
        return False
    except Exception as e:
        print(f"An error occurred: {e}")
        return False

def main():
    try:
        # Take input from the user
        user_input = input("Enter a number to check if it is an Armstrong number: ")
        
        # Try to convert the input to an integer
        number = int(user_input)
        
        # Check for Armstrong number
        if is_armstrong_number(number):
            print(f"{number} is an Armstrong number.")
        else:
            print(f"{number} is not an Armstrong number.")
    
    except ValueError:
        print("Invalid input! Please enter a valid integer.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()

