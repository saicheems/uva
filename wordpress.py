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
srcJavaName = 'src/' + sys.argv[1] + '/' + 'Main.java'
srcCppFile = None
srcJavaFile = None

if os.path.exists(srcCppName):
  srcCppFile = open(srcCppName, 'r')
if os.path.exists(srcJavaName):
  srcJavaFile = open(srcJavaName, 'r')
if srcCppFile is None and srcJavaFile is None:
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
if srcCppFile is not None:
  print '[code language=cpp]'
  print srcCppFile.read() + '[/code]'
if srcJavaFile is not None:
  print '[code language=java]'
  print srcJavaFile.read() + '[/code]'
print '[code title="input"]'
print inFile.read() + '[/code]'
print '[code title="output"]'
print outFile.read() + '[/code]'
