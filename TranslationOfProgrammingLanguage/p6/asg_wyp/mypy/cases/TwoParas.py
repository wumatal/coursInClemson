def f(x, y):
  if x > y:
    return x % y
  else:
    return x % -y

print f( 15, 7 )
print f( 7, 15 )
