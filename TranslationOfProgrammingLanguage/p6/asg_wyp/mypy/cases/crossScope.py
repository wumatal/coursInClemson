x = 1
def f():
  print x

def g():
  x = 2
  print x
  def h():
    print x+10
  h()
  f()
  k()

def k():
  print x
  def j():
    print x*3
  j()
  f()

g()

k()
f()
