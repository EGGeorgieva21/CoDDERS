import string
import csv


filename = str(input("What'cha lookin for? \n"))

# string arr[100] = 
with open('../ggr/userData/' + filename + '.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    print("Found it! Here's the will: ")

    for row in spamreader:
        print(' '.join(row))