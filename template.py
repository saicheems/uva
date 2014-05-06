#!/usr/bin/python

import os
import sys

if len(sys.argv) != 2:
  print 'Requires one argument - an unused UVa problem number.'
  sys.exit(0)

if not sys.argv[1].isdigit():
  print 'Argument must be a positive integer.'
  sys.exit(0)

if os.path.exists('src/' + sys.argv[1]):
  print 'Path to problem already exists. Exiting...'
  sys.exit(0)
else:
  os.makedirs('src/' + sys.argv[1])

print 'Writing source file...'
srcFile = open('src/' + sys.argv[1] + '/' + sys.argv[1] + '.cpp', 'w+')
srcFile.write(
  '/*\n' +
  ' * Sai Cheemalapati\n' +
  ' * UVa ' + sys.argv[1] + ': ###PROBLEM NAME###\n' +
  ' */\n' +
  '\n' +
  '#include <cstdio>\n' +
  '\n' +
  'int main () {\n' +
  '\n' +
  '}\n')
srcFile.close()
print 'Writing make file...'
makeFile = open('src/' + sys.argv[1] + '/Makefile', 'w+')
makeFile.write(
  'all:\n'
  '\tg++ ' + sys.argv[1] + '.cpp -o ' + sys.argv[1] + '\n')
makeFile.close()
