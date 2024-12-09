def matrix_input(rows, cols):
    """Function to take matrix input from the user."""
    matrix = []
    print(f"Enter the elements of the {rows}x{cols} matrix:")
    for i in range(rows):
        row = []
        for j in range(cols):
            while True:
                try:
                    val = int(input(f"Enter element [{i+1},{j+1}]: "))
                    row.append(val)
                    break
                except ValueError:
                    print("Invalid input! Please enter an integer.")
        matrix.append(row)
    return matrix

def matrix_multiply(A, B):
    """Function to multiply two matrices A and B."""
    # Get dimensions of the matrices
    nA, mA = len(A), len(A[0])
    nB, mB = len(B), len(B[0])

    # Check if multiplication is possible (columns of A should match rows of B)
    if mA != nB:
        raise ValueError("Matrix multiplication is not possible: columns of A must be equal to rows of B.")

    # Initialize the product matrix with zeros
    result = [[0 for _ in range(mB)] for _ in range(nA)]

    # Perform matrix multiplication
    for i in range(nA):
        for j in range(mB):
            try:
                result[i][j] = sum(A[i][k] * B[k][j] for k in range(mA))
            except OverflowError:
                print("Overflow occurred during multiplication!")
                return None

    return result

def print_matrix(matrix):
    """Function to print the matrix."""
    for row in matrix:
        print(" ".join(map(str, row)))

def main():
    try:
        # Input for the first matrix
        rows_A = int(input("Enter the number of rows for matrix A: "))
        cols_A = int(input("Enter the number of columns for matrix A: "))
        A = matrix_input(rows_A, cols_A)

        # Input for the second matrix
        rows_B = int(input("Enter the number of rows for matrix B: "))
        cols_B = int(input("Enter the number of columns for matrix B: "))
        B = matrix_input(rows_B, cols_B)

# Perform matrix multiplication
        result = matrix_multiply(A, B)

        if result is not None:
            print("\nResulting Matrix (A * B):")
            print_matrix(result)

    except ValueError as ve:
        print(f"Error: {ve}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()


