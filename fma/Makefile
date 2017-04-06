TARGET := demo.out
STATICLIB := libfma.a
SHAREDLIB := libfma.so
LIBSRC := fma.c
LIBOBJ := $(LIBSRC:.c=.o)
LIBDEP := $(LIBOBJ:.o=.d)
MAINSRC := main.c
MAINOBJ := $(MAINSRC:.c=.o)
MAINDEP := $(MAINOBJ:.o=.d)
DEPS := $(LIBDEP) $(MAINDEP)
OBJS := $(MAINOBJ) $(LIBOBJ)

CPPFLAGS += -MMD
CPPFLAGS += -MP

CFLAGS := -fPIC
CFLAGS += -mfma

all : $(TARGET) $(STATICLIB) $(SHAREDLIB)

$(TARGET): main.o $(STATICLIB) fma.go
	gcc -o $@ $(filter %.o,$^) $(STATICLIB)
	strip $@
	go build fma.go

%.o : %.c
	gcc $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(STATICLIB): $(LIBOBJ)
	ar rcs $@ $^

$(SHAREDLIB): $(LIBOBJ)
	gcc -shared -o $@ $^

clean:
	rm -f *.o *.a *.d *.so $(TARGET) fma

-include $(DEPS)
