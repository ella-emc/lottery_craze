# Ask for the winning combination from the user
# Read the numbers from the file
# If the entry from the file matches 6 numbers, write it to another file
# If the entry from the file matches 5 numbers, write it to another file
# If the entry from the file matches 4 numbers, write it to another file
# If the entry from the file matches 3 numbers, write it to another file

# Count the number of winning entries in 6, 5, 4, and 3 combinations
# Display the amount of prize for each and the total amount of prize in each number category
import sys, csv

def main():
    display_home()
    combination = input("Enter today's 6-number winning combination: ")
    
    # Check if input is separated by space
    try:
        entries = combination.split(" ")
    except ValueError:
        sys.exit("Invalid input")
    
    # Check if range of number inputs is 1-59 inclusive
    for entry in entries:
        if int(entry) < 1 or int(entry) > 59:
            sys.exit("Invalid range of numbers (must be 1-59)")

    # Read the file
    with open("lottery_NY_lotto_winning_numbers_formatted.csv") as dataset:
        reader = csv.reader(dataset)



def display_home():
    print("**************************************************")
    print("                LOTTERY CRAZE")
    print("**************************************************")


if __name__ == "__main__":
    main()