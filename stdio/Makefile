CFLAGS=`pkg-config libgvc glu --cflags`
LDFLAGS=`pkg-config libgvc glu --libs` -lglut

CC=gcc
APP=main

src=$(shell find . -name "*.c")
deps=$(shell find . -name "*.h")
obj=$(src:%.c=%.o)

# build *.o to app.
$(APP): $(obj)
	$(CC) -o $(APP) $(obj) $(LDFLAGS)


# build *.c and *.h to *.o
%.o : %.c $(deps)
	$(CC) -c $< -o $@ $(CFLAGS)

run:$(APP)
	./$(APP)

clean:
	rm -rf $(obj) $(APP)
