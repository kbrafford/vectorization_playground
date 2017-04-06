CTARGET := democ
STATICLIB := libfma.a
SHAREDLIB := libfmashared.so
GOTARGET := demogo
LIBSRC := fma.c
LIBOBJ := $(LIBSRC:.c=.o)
LIBDEP := $(LIBOBJ:.o=.d)
MAINSRC := main.c
MAINOBJ := $(MAINSRC:.c=.o)
MAINDEP := $(MAINOBJ:.o=.d)
GOSRC := fma.go
DEPS := $(LIBDEP) $(MAINDEP)
OBJS := $(MAINOBJ) $(LIBOBJ)

CPPFLAGS += -MMD
CPPFLAGS += -MP

CFLAGS := -fPIC
CFLAGS += -mfma

all : $(CTARGET) $(STATICLIB) $(SHAREDLIB) $(GOTARGET)

$(CTARGET): main.o $(STATICLIB) fma.go
	gcc -o $@ $(filter %.o,$^) $(STATICLIB)
	strip $@

$(GOTARGET): $(GOSRC) $(STATICLIB)
	go build -o $(GOTARGET) $(GOSRC)

%.o : %.c
	gcc $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(STATICLIB): $(LIBOBJ)
	ar rcs $@ $^

$(SHAREDLIB): $(LIBOBJ)
	gcc -shared -o $@ $^

clean:
	rm -f *.o *.a *.d *.so $(CTARGET) $(GOTARGET)

-include $(DEPS)
