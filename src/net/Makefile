all: s.out c.out a.out

s.out: fstst.cpp fileserver.cpp server.cpp
	g++ -o s.out fstst.cpp fileserver.cpp server.cpp

c.out: cltst.cpp client.cpp
	g++ -o c.out cltst.cpp client.cpp

a.out: hello.cpp
	g++ hello.cpp

clean:
	rm -rf *.out *.stackdump *~
