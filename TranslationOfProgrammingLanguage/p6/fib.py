def f(x):
    if x < 0 :
        print "Input Must >= 0!"
        return
    if x <= 1:
        return 1
    else:
        return f(x-1)+f(x-2)

print f(0)
print f(1)
print f(2)
print f(3)
print f(4)
print f(5)
print f(6)
print f(7)
