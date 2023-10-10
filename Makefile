all: isomorphic

# optional:
# sh getlibs.sh

# Required
webview.o: webview.cc
	g++ -c webview.cc -std=c++11 -DWEBVIEW_STATIC -o webview.o

isomorphic.o: isomorphic.c	
	gcc -c isomorphic.c -std=c99 

isomorphic: isomorphic.o webview.o
	g++ isomorphic.o webview.o -framework WebKit -o isomorphic 

install:
	cp ./isomorphic /usr/local/lib/.

clean:
	rm *.o rm isomorphic

