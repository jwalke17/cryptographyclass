all: setup elgamal

setup: setup.cpp
	g++ $< -lgmpxx -lgmp -o $@

elgamal: elgamal.cpp
	g++ $< -lgmpxx -lgmp -o $@

clean:
	rm setup elgamal
