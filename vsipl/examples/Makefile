CPPFLAGS:=-I/usr/local/include 
LDFLAGS:=-L/usr/local/lib
LIBS:=-lvsipl
CC:=cc

%: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LIBS)
