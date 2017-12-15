x = 3
def f( x, y ):
  if x == y:
    return

  if x > y:
    return x

  if x < y:
    return y

print f( 7, 7.0)
print f( 7, 7.7)
print f( 7.7, 7)
