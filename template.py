#!/usr/bin/python

import os
import sys

if len(sys.argv) != 3:
  print 'Requires two argument - an unused UVa problem number and a language (java or cpp).'
  sys.exit(0)

if not sys.argv[1].isdigit():
  print 'First argument must be a positive integer.'
  sys.exit(0)

if sys.argv[1] is not 'java' and not 'cpp':
  print 'Second argument must be either java or cpp.'
  sys.exit(0)

if os.path.exists('src/' + sys.argv[1]):
  print 'Path to problem already exists. Exiting...'
  sys.exit(0)
else:
  os.makedirs('src/' + sys.argv[1])

print 'Writing source file...'
if sys.argv[2] == 'cpp':
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
else:
  srcFile = open('src/' + sys.argv[1] + '/Main.java', 'w+')
  srcFile.write(
    '/*\n' +
    ' * Sai Cheemalapati\n' +
    ' * UVa ' + sys.argv[1] + ': ###PROBLEM NAME###\n' +
    ' */\n' +
    '\n' +
    'import java.util.Scanner;\n' +
    '\n' +
    'class Main {\n' +
    '  public static void main (String args[]) {\n' +
    '\n' +
    '  }\n' +
    '}\n')

srcFile.close()

print 'Writing make file...'
makeFile = open('src/' + sys.argv[1] + '/Makefile', 'w+')
if sys.argv[2] == 'cpp':
  makeFile.write(
    'all:\n'
    '\tg++ ' + sys.argv[1] + '.cpp -o ' + sys.argv[1] + '\n')
else:
  makeFile.write(
    'all:\n'
    '\tjavac Main.java\n')
makeFile.close()
