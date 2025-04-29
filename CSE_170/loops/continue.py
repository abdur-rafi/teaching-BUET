# while loop

numberOfStudents = int(input("Enter the number of students: "))

iterationCount = 0

marskSum = 0
presentStudents = 0
maxMarks = 0
minMarks = 100

for iterationCount in range(1 , numberOfStudents):
    studentMark = int(input(f"Enter mark of student no.{iterationCount}: "))
    if studentMark < 0 :
        print("Student is considered absent.")
        continue

    if studentMark > maxMarks:
        maxMarks = studentMark
    
    if studentMark < minMarks:
        minMarks = studentMark
    
    presentStudents += 1
    marskSum += studentMark


average = marskSum / presentStudents
print(f"The average mark of the students is: {average}")
print(f"The maximum mark is: {maxMarks}")
print(f"The minimum mark is: {minMarks}")
