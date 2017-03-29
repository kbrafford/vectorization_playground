TARGET = demo.out

$(TARGET): main.o libfma.a fma.go
	gcc main.o libfma.a -o $@
	strip $@
	go build fma.go

main.o: main.c
	gcc -c $< -o $@

libfma.a: fma.o
	ar rcs $@ $^

fma.o: fma.c fma.h
	gcc -c -mfma -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)
