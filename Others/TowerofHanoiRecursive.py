steps = 0
def tohr (n, r1, r2, ri) :
    global steps
    steps += 1
    if n == 1 :
        print ("Disk 1 shifted from %s to %s" % (r1, r2))
        return 
    tohr (n-1, r1, ri, r2)
    print ("Disk %d shifted from %s to %s" % (n, r1, r2))
    tohr (n-1, ri, r2, r1)
    return "The number of steps performed is : %d" % (steps)
    
n = int (raw_input ("Enter the number of disks : "))
print (tohr (n, 'start rod', 'end rod', 'mid rod'))
