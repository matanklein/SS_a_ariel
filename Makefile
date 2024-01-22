CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB_LOOP=basicClassification.o advancedClassificationLoop.o
OBJECTS_LIB_RECURSION=basicClassification.o advancedClassificationRecursion.o
FLAGS = -Wall -g


all: loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a
libclassloops.a: $(OBJECTS_LIB_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LIB_LOOP)

recursives: libclassrec.a
libclassrec.a: $(OBJECTS_LIB_RECURSION) 
	$(AR) -rcs libclassrec.a $(OBJECTS_LIB_RECURSION)

recursived: libclassrec.so
libclassrec.so: $(OBJECTS_LIB_RECURSION) 
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIB_RECURSION)

loopd: libclassloops.so
libclassloops.so: $(OBJECTS_LIB_LOOP) 
	$(CC) -shared -o libclassloops.so $(OBJECTS_LIB_LOOP)

mains: libclassrec.a $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a

maindloop: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so
	
maindrec: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.o NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.o NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c

clean:
	rm -f *.o *.a *.so mains maindloop maindrec