def divide(x, y):
	try:
		result = x / y
	except ZeroDivisionError:
		print "division by zero!"
	else:
		print "result is", result
	finally:
		for x in range(3):
			if x < 3:
				print x
			else:
				print x+1
		print "executing finally clause"