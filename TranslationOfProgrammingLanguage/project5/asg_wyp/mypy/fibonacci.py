def f(x):
  if x == 0 or x==1:
    return 1;
  else:
    return f(x-2)+f(x-1)

print f(0)
print f(1)
print f(2)
print f(3)
print f(4)
print f(5)
print f(6)
print f(7)
