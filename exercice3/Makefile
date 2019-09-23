src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lGL -lz -lm

Exercice3output:	$(obj)
	@$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) Exercice3output