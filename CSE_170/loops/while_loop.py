# while loop

numberOfStudents = int(input("Enter the number of students: "))

while numberOfStudents <= 0:
    print("Invalid number of students. Please enter a positive number.")
    numberOfStudents = int(input("Enter the number of students: "))
else:
    print("Valid number of students entered. Continuing with the program.")

iterationCount = 1

marksSum = 0

while iterationCount <= numberOfStudents:
    studentMark = int(input(f"Enter mark of student no.{iterationCount}: "))
    while studentMark < 0 or studentMark > 100:
        print("Invalid mark. Please enter a mark between 0 and 100.")
        studentMark = int(input(f"Enter mark of student no.{iterationCount}: "))
    else:
        print("Valid mark entered.")
    marksSum += studentMark
    iterationCount += 1
else:
    print("All marks entered successfully.")


average = marksSum / numberOfStudents
print(f"The average mark of the students is: {average}")
