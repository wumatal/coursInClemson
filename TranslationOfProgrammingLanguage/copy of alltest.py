#!/usr/bin/python

import os
import sys
import fnmatch
import subprocess
import filecmp

EXECUTABLE = os.path.join(os.getcwd(), 'run')
LIB_FOLDER = os.path.join(os.getcwd(), '../Python-2.7.2/')


class TestHarness:
    def __init__(self):
        self.Passed = 0
        self.Failed = 0
        self.makeExecutable()

    @classmethod
    def makeExecutable(cls):
        if not os.path.isfile(EXECUTABLE):
            retcode = subprocess.call('make', shell=True)
            assert retcode == 0, '\tFAILED to make the parser'
        else:
            retcode = subprocess.call("make clean",shell=True)
            if retcode > 0:
              print "\tFAILED to make clean the scanner"
            retcode = subprocess.call("make",shell=True)
            if retcode > 0:
              print "\tFAILED to make the scanner"

    def testCode(self, retcode, testcase):
        if retcode > 0:
            print testcase, 'failed'
            self.Failed += 1
        else:
            # print testcase, 'passed'
            self.Passed += 1

    def generateAndSortMccabeResult(self, testFile, outFile):
      retcode = subprocess.call("python -m mccabe " + testFile + " > " + outFile, shell=True)
      if retcode > 0:
        print "\tFAILED to make the out by mccabe"
      output = testFile[:-3]+".out"
      with open(output, 'r') as f:
        lines = f.readlines()
      f.close()
      _toBeSorted = {}
      for line in lines:
          if ':' in line:
              lineNum = int(line[2:int(line.find(':'))])
          else:
              lineNum = int(line[int(line.find(' ')):int(line.find(','))-1])
          _toBeSorted[lineNum] = line
      with open(output, 'w') as f:
        for key in sorted(_toBeSorted):
          f.write(_toBeSorted[key])
      f.close()

    def testOneFile(self, root, filename):
        testcase = os.path.join(root, filename)
        output = testcase[:-3]+".out"
        self.generateAndSortMccabeResult(testcase, output)

        retcode = subprocess.call("./run < "+testcase+"> /tmp/out",shell=True)
        if retcode > 0:
            print "\tFAILED to run test case "+filename
        else:
            if not os.path.isfile( output ):
                print "test case", x[:-3]+'.out', "doesn't exist"
                sys.exit( 1 )
            if not filecmp.cmp("/tmp/out", output): 
                print "\tTEST CASE FAILED", filename
                self.Failed += 1
            else :
                print "testcase:", filename, "passed"
                self.Passed += 1

    def testDirectory(self, testDir):
        assert os.path.isdir(testDir), testDir + 'must be a directory'
        for root, dirs, files in os.walk(testDir):
            for filename in files:
                if filename.endswith('.py'):
                    self.testOneFile(root, filename)
                    testcase = os.path.join(root, filename)
                    retcode = subprocess.call("rm " + testcase[:-3] + ".out",shell=True)

    def runTestCases(self, testPath):
        if os.path.isdir(testPath):
                self.testDirectory(testPath)
        elif os.path.isfile(testPath):
                self.testOneFile(os.getcwd(), testPath)

    def __str__(self):
        return ('\t%d test cases Passed\n' % self.Passed) +  \
                     ('\t%d test cases Failed' % self.Failed)


if __name__ == '__main__':
    testcases = []
    if len(sys.argv) <= 1:
        testcases = [LIB_FOLDER]
    else:
        testcases = sys.argv[1:]
    harness = TestHarness()
    for t in testcases:
        harness.runTestCases(t)
    print harness
