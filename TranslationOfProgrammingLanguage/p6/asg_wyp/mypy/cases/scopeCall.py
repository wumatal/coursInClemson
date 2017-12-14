

def j():
  x=3
  print x

def g():
  x=2
  def j():
    print x
  j()


g()
