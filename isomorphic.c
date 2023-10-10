#include "webview.h"
#include <stddef.h>

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

 char * URL =  "http://127.0.0.1:3000/root";

  if (argc==2) {
    URL = argv[1];
  }

  webview_t w = webview_create(0, NULL);
  webview_set_title(w, "Basic Example");
  webview_set_size(w, 480, 320, WEBVIEW_HINT_NONE);
  webview_navigate(w, URL); 
  webview_run(w);
  webview_destroy(w);
  return 0;
}

