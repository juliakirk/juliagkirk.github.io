#!/usr/bin/env python
# coding: utf-8
import csv
import pprint
import argparse

shares = dict()
amount = dict()


parser = argparse.ArgumentParser()
parser.add_argument('filename')
args = parser.parse_args()

with open(args.filename) as csvfile:
    foundHeader = False
    reader529 = csv.reader(csvfile)
    for row in reader529:
        #print(row)
        #print(len(row))
        if len(row) == 10:
            
            if foundHeader == True:
                #print(row[5],row[7],row[9][1:])
                if row[5] in shares:
                    shares[row[5]]= float(row[7]) + shares[row[5]]
                    amount[row[5]]= float(row[9][1:]) + amount[row[5]]
                else:
                    shares[row[5]] = float(row[7])
                    amount[row[5]] = float(row[9][1:])
            else:
                foundHeader = True
#pprint.pprint(shares)
#pprint.pprint(amount)

for share in shares:
    print(f'{share} buy {shares[share]:.4f} at ${amount[share]/shares[share]:.4f} for a total of ${amount[share]:.4f}')
