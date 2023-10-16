#include "webview.h"
#include <stddef.h>

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>    
#include <stdlib.h>   

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow) {
  (void)hInst;
  (void)hPrevInst;
  (void)lpCmdLine;
  (void)nCmdShow;
#else

int main(int argc, char** argv) {
#endif


   int opt;
    char *pvalue = NULL;
    char *tvalue = NULL;
    char *wvalue = NULL;
    char *hvalue = NULL;

    while ((opt = getopt(argc, argv, "p:t:w:h:")) != -1) {
        switch (opt) {
            
            // Path
            case 'p':
                pvalue = optarg;
                printf("Option -p (Path) with argument %s\n", pvalue);
                break;
            
            // Title    
            case 't':
                tvalue = optarg;
                printf("Option -t (Title) with argument %s\n", tvalue);
                break;
            
            // Width
            case 'w':
                wvalue = optarg;
                printf("Option -w (Width) with argument %s\n", wvalue);
                break;
            
            // Height   
            case 'h':
                hvalue = optarg;
                printf("Option -h (Height) with argument %s\n", hvalue);
                break;
  
            case '?':
                if (optopt == 'c')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                    printf("Usage ./isomorphic -p path -t title -x position -s size");
                return 1;
            default:
                exit(EXIT_FAILURE);
        }
    }

  // Path
  char * URL = pvalue;
  
  // Title
  char * title = tvalue;

  // Width
  int width = atoi(wvalue);
  
  // Height
  int height = atoi(hvalue);

  webview_t w = webview_create(0, NULL);
  webview_set_title(w, title);
  webview_set_size(w, width, height, WEBVIEW_HINT_NONE);
  webview_navigate(w, URL); 
  webview_run(w);
  webview_destroy(w);
  return 0;
}