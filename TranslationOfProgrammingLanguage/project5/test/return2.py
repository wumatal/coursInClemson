
def f():
  x = 2
  print x
  x += 1
  print x
  return
  print x

def g():
  x = 1
  print x
  f()
  return
  f()

g()
