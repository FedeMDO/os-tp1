src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lGL -lz -lm

Exercice3:	$(obj)
	@$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog