CC       = gcc
CFLAGS   = -g -O0 -Wall

TARGETS = httpd server client

.c:
	$(CC) $(CFLAGS) $< -o $@

all: $(TARGETS)

clean:
	rm -f $(TARGETS)