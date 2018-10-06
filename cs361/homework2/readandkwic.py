import sys
import time
from mykwic import kwic

fn = sys.argv[1]

with open(fn,'r') as f:
    data = f.read()
print len(data)
start = time.time()
kout = kwic(data,periodsToBreaks=True,listPairs=True)
print len(kout)
print "ELAPSED:",time.time()-start
