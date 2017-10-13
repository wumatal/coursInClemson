#!/usr/bin/python

import os, sys
import fnmatch
import subprocess
import filecmp

def testCode( retcode, msg ):
    if retcode > 0:
        print msg
        sys.exit( 1 )

testDir = os.path.join( os.getcwd(), 'cases')
if not os.path.isdir( testDir ):
    print testDir, "isn't a directory"
    sys.exit( 1 )

executable = os.path.join(os.getcwd(), "run")
if not os.path.isfile( executable ):
    retcode = subprocess.call("make",shell=True)
    testCode( retcode, "\tFAILED to make the scanner" )


def compare_with_mccabe(mccabe_file, out):
    retcode = subprocess.call("python -m mccabe "+mccabe_file+">"+out, shell=True)
    fileH = open(out)
    lines = fileH.readlines()
    fileH.close()
    _toBeSorted = {}
    for line in lines:
        if ':' in line:
            lineNum = int(line[2:int(line.find(':'))])
        else:
            lineNum = int(line[int(line.find(' ')):int(line.find(','))-1])
        #print lineNum
        _toBeSorted[lineNum] = line

    fileH = open(out, 'w')
    for key in sorted(_toBeSorted, reverse=True):
        fileH.write(_toBeSorted[key])
    fileH.close()


files = os.listdir( testDir )
for x in files:
    if fnmatch.fnmatch(x, "*.py"):
        testcase = os.path.join(testDir, x)
        output = testcase[:-3]+".out"
        compare_with_mccabe(testcase, output)

        retcode = subprocess.call("./run < "+testcase+"> /tmp/out",shell=True)
        if retcode != 0:
            testCode( retcode, "\tFAILED to run test case "+x)
        else:
            if not os.path.isfile( output ):
                print "test case", x[:-3]+'.out', "doesn't exist"
                sys.exit( 1 )
            if not filecmp.cmp("/tmp/out", output): 
                print "\tTEST CASE FAILED", x
            else :
                print "testcase:", x, "passed"

