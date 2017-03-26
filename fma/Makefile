TARGET = demo.out

$(TARGET): main.o libfma.a
	gcc $^ -o $@
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
