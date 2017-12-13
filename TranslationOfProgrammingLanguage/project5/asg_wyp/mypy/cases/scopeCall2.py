def f1():
  x = 1
  print x
  def g3():
    x=10
    print x

def f2():
  x = 2
  def g1():
    x=3
    print x
  def g2():
    x=4
    print x
    g1()
    f1()
  f1()
  g2()
f2()
