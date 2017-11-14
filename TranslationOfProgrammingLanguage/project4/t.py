#!/usr/bin/python

import os, sys
import fnmatch
import subprocess
import filecmp
import re

def testCode( retcode, msg ):
    if retcode > 0:
        print msg
        sys.exit( 1 )

testDir = os.path.join( os.getcwd(), 'my')
if not os.path.isdir( testDir ):
    print testDir, "isn't a directory"
    sys.exit( 1 )


def writeOutput(testcase, outputFile):
    retcode = subprocess.call("python " + testcase + ">" + outputFile, shell=True)

files = os.listdir( testDir )
for x in files:
    if fnmatch.fnmatch(x, "*.py"):
        testcase = os.path.join(testDir, x)
        output = testcase[:-3]+".out"
        writeOutput(testcase, output)
