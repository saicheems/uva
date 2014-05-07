#!/usr/bin/python

import os
import sys

if len(sys.argv) != 2:
  print 'Requires one argument - an used UVa problem number. Exiting...'
  sys.exit(0)

if not sys.argv[1].isdigit():
  print 'Argument must be a positive integer. Exiting...'
  sys.exit(0)

if not os.path.exists('src/' + sys.argv[1]):
  print 'Path to problem doesn\'t exist. Exiting...'
  sys.exit(0)

srcCppName = 'src/' + sys.argv[1] + '/' + sys.argv[1] + '.cpp'
srcJavaName = 'src/Main.java'
srcFile = None

# If the file is a cpp file, isCpp should be set to true.
isCpp = False

if os.path.exists(srcCppName):
  srcFile = open(srcCppName, 'r')
  isCpp = True
elif os.path.exists(srcJavaName):
  srcFile = open(srcJavaName, 'r')
else:
  print 'Expected source file not found. Exiting...'
  sys.exit(0)

desName = 'src/' + sys.argv[1] + '/' + sys.argv[1] + '.txt'
if not os.path.exists(desName):
  print 'Expected description file not found. Exiting...'
  sys.exit(0)

desFile = open(desName, 'r')

inName = 'src/' + sys.argv[1] + '/in.txt'
outName = 'src/' + sys.argv[1] + '/out.txt'

if not os.path.exists(inName):
  print 'Expected input file not found. Exiting...'
  sys.exit(0)
if not os.path.exists(outName):
  print 'Expected output file not found. Exiting...'
  sys.exit(0)

inFile = open(inName, 'r')
outFile = open(outName, 'r')

print ' '.join([line.rstrip('\n') for line in desFile])
print '[code language=' + ('cpp' if isCpp else 'java') + ']'
print srcFile.read() + '[/code]'
print '[code title="input"]'
print inFile.read() + '[/code]'
print '[code title="output"]'
print outFile.read() + '[/code]'
