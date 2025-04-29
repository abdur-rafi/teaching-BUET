
marksSum = 0
studentsCount = 0
maxMarks = 0
minMarks = 100

while True:
    studentMark = int(input("Enter the mark of the student (or -1 to finish): "))
    
    if studentMark == -1:
        break
    
    if studentMark < 0 or studentMark > 100:
        print("Invalid mark. Please enter a mark between 0 and 100.")
        continue
    
    marksSum += studentMark
    studentsCount += 1
    if studentMark > maxMarks:
        maxMarks = studentMark
    if studentMark < minMarks:
        minMarks = studentMark

if studentsCount > 0:
    average = marksSum / studentsCount
    print(f"The average mark of the students is: {average}")
    print(f"The maximum mark is: {maxMarks}")
    print(f"The minimum mark is: {minMarks}")
    print(f"The number of students is: {studentsCount}")
else:
    print("No valid marks were entered.")