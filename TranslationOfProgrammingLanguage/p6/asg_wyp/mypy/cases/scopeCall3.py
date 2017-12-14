x = 1
def f():
  print x

def g():
  x = 2
  def f():
    print x
  f()

g()
f()
