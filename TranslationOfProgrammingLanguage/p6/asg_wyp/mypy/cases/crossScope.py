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


g()
f()
