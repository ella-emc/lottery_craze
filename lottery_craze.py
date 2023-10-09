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
    combination = input("  Enter today's 6-number winning combination: ")
    entries = []

    # Counter for winners in each number combination
    six_number_winners = 0
    five_number_winners = 0
    four_number_winners = 0
    three_number_winners = 0

    entries = combination.split("-") if "-" in combination else combination.split(" ")
    
    # Check if range of number inputs is 1-59 inclusive
    for entry in entries:
        if int(entry) < 1 or int(entry) > 59:
            sys.exit("Invalid range of numbers (must be 1-59)")
    
    entries = [int(entry) for entry in entries]

    # Read the file
    with open("lottery_NY_lotto_winning_numbers_formatted.csv") as dataset:
        reader = csv.reader(dataset)
        for line in reader:
            same = 0
            date = line[0]
            numbers = [int(num) for num in line[1].split()]
           
            # Compare number in input to number in dataset
            for number in numbers:
                for entry in entries:
                    if number == entry:
                        same += 1
                        break

            match same:
                case 6:
                    six_number_winners += 1
                    write_to_six(date, numbers)
                case 5:
                    five_number_winners += 1
                    write_to_five(date, numbers)
                case 4:
                    four_number_winners += 1
                    write_to_four(date, numbers)
                case 3:
                    three_number_winners += 1
                    write_to_four(date, numbers)

    displayWinners(six_number_winners, five_number_winners, four_number_winners, three_number_winners)
    

def display_home():
    print("**********************************************************************")
    print("                          LOTTERY CRAZE")
    print("**********************************************************************")


def write_to_six(win_date, win_num):
    with open("six_number_winners.csv", "a") as six_num_file:
        six_num_file.write(f"{win_date},{win_num}")


def write_to_five(win_date, win_num):
    with open("five_number_winners.csv", "a") as five_num_file:
        five_num_file.write(f"{win_date},{win_num}")


def write_to_four(win_date, win_num):
    with open("four_number_winners.csv", "a") as four_num_file:
        four_num_file.write(f"{win_date},{win_num}")


def write_to_three(win_date, win_num):
    with open("three_number_winners.csv", "a") as three_num_file:
        three_num_file.write(f"{win_date},{win_num}")


def displayWinners(six, five, four, three):
    print("\n**********************************************************************")
    print(f"   Six-combination winners: {six}")
    print(f"   Five-combination winners: {five}")
    print(f"   Four-combination winners: {four}")
    print(f"   Three-combination winners: {three}")
    print("\n**********************************************************************")

if __name__ == "__main__":
    main()