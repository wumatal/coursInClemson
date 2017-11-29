EXEC = hoppe
LIBS = -lm -lstdc++ -lGLU -lGL -L. -lX11
IFLAGS = -I ../.. -I ../../..
CXXFLAGS = $(IFLAGS) -O3
CFLAGS = $(IFLAGS) -O3
OBJS = main.o mesh.o osLinux.o vector.o subdivide.o edge_hash.o

hoppe: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

%.o: source/%.cpp
	$(CXX) -c $+ $(CXXFLAGS)

%.o: source/%.c
	$(CXX) -c $+ $(CFLAGS)

clean:
	-rm -f $(OBJS) core *~ source/*~

clobber: clean
	-rm -f hoppe

run: hoppe
	./hoppe

release: clobber
	-rm -f ../hoppe.tar.gz
	-rm -f ../hoppe.tar
	tar -cvf ../hoppe.tar \
		../hoppe/source/*.h \
		../hoppe/source/*.c \
		../hoppe/Makefile \
		../hoppe/hoppe.vcproj \
		../hoppe/meshes/*.m
	gzip ../hoppe.tar
