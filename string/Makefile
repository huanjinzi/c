CC=gcc
APP=main

deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.c")

obj=$(src:%.c=%.o)# replace .c to .o

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
