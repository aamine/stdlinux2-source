TARGETS = calc dlcalc

all: $(TARGETS)

calc: calc.c
	gcc -g -Wall calc.c -lm -o $@

dlcalc: dlcalc.c
	gcc -g -Wall dlcalc.c -ldl -lm -o $@

clean:
	rm -f $(TARGETS)
