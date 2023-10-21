# Isomorphic
Minimalist browser for web-based desktop apps, based on WebView

# Installation

```
git clone https://github.com/serge-hulne/isomorphic
cd isomorphic
make
make install
```

# Dependencies on Linux (or MingW): 
- libwebkit2gtk-4.0-dev
- libgtk : gtk+-3.0
(See your package manager for instructions ("apt-get" or "yum" or "pacman", or other, depending upon your linux distribution))

# Dependencies on Mac
brew install gtk+3

(on Linux : `sudo make install` (Ubuntu) or `make install` as root (Debian))

# Usage 
## Examples
```
1. isomorphic -p http://www.google.com
2. isomorphic -p http://www.google.com -t Testing -w 400 -h 300 

```
