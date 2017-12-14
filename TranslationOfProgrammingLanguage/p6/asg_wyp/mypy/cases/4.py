def f():
    x = 7
    print x
    def g():
        y = 17
        print y
        def h():
            z = 77
            print z
        h()
        print y
    g()
    print x

f()
