/* Cockos SWELL (Simple/Small Win32 Emulation Layer for Linux/OSX)
   Copyright (C) 2006 and later, Cockos, Inc.

    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
*/
  
#ifdef SWELL_PROVIDED_BY_APP

#define SWELL_API_DEFPARM(x)
#define SWELL_API_DEFINE(ret,func,parms) ret (*func) parms ;
extern "C" {
#include "swell.h"
};

// only include this file in projects that are linked to swell.dylib

struct SWELL_CursorResourceIndex *SWELL_curmodule_cursorresource_head;
struct SWELL_DialogResourceIndex *SWELL_curmodule_dialogresource_head;
struct SWELL_MenuResourceIndex *SWELL_curmodule_menuresource_head;

// define the functions

static struct
{
  const char *name;
  void **func;
} api_tab[]={
  
#undef _WDL_SWELL_H_API_DEFINED_
#undef SWELL_API_DEFINE
#define SWELL_API_DEFINE(ret, func, parms) {#func, (void **)&func },

#include "swell.h"
  
};

static int dummyFunc() { return 0; }

#ifdef SWELL_LOAD_SWELL_DYLIB
static void *(*__loaded_getfunc)(const char *name)=NULL;
#endif
class SwellAPPInitializer
{
public:
  SwellAPPInitializer()
  {
    void *(*SWELLAPI_GetFunc)(const char *name)=NULL;
#ifdef SWELL_LOAD_SWELL_DYLIB
    char fn[4096];
    const int nSize=sizeof(fn)-64;
    char lnk[64];
    sprintf(lnk,"/proc/%d/exe",getpid());
    int sz=readlink(lnk,fn,nSize);
    if (sz<0)sz=0;
    else if (sz>=nSize)sz=nSize-1;
    fn[sz]=0;
    char *p=fn;
    while (*p) p++;
    while (p >= fn && *p != '/') p--;
    strcpy(++p,"libSwell.so");

    void *tmp = dlopen(fn,RTLD_LAZY);
    if (!tmp)
    {
      printf("Error loading '%s': %s\n",fn,dlerror());
      exit(2);
    }
    const char *preload_fn = (const char *)dlsym(tmp,"SWELL_WANT_LOAD_LIBRARY");
    if (preload_fn && *preload_fn)
      dlopen(preload_fn,RTLD_LAZY|RTLD_GLOBAL);

#else
    void *tmp = dlopen(NULL,RTLD_LAZY);
#endif

    if (tmp) *(void **)&SWELLAPI_GetFunc = dlsym(tmp,"SWELLAPI_GetFunc"); 
    //printf("tmp=%08x, SWELLAPI_GetFunc=%08x\n",tmp,SWELLAPI_GetFunc);
      
    if (SWELLAPI_GetFunc && SWELLAPI_GetFunc(NULL)!=(void*)0x100) SWELLAPI_GetFunc=0;
      
#ifdef SWELL_LOAD_SWELL_DYLIB
    __loaded_getfunc = SWELLAPI_GetFunc;
#endif
    int x;
    for (x = 0; x < sizeof(api_tab)/sizeof(api_tab[0]); x ++)
    {
      *api_tab[x].func=SWELLAPI_GetFunc?SWELLAPI_GetFunc(api_tab[x].name):0;
      if (!*api_tab[x].func)
      {
        printf("SWELL API not found: %s\n",api_tab[x].name);
#ifdef SWELL_LOAD_SWELL_DYLIB
        exit(1);
#endif
        *api_tab[x].func = (void*)&dummyFunc;
      }
    }
  }
  ~SwellAPPInitializer()
  {
  }
};

SwellAPPInitializer m_swell_appAPIinit;

#ifdef SWELL_LOAD_SWELL_DYLIB
extern "C" __attribute__ ((visibility ("default"))) void *SWELLAPI_GetFunc(const char *name)
{
  if (__loaded_getfunc) return __loaded_getfunc(name);
  return NULL;
}

#endif

extern "C" __attribute__ ((visibility ("default"))) int SWELL_dllMain(HINSTANCE hInst, DWORD callMode, LPVOID _GetFunc)
{
  // this returning 1 allows DllMain to be called, if available
  return 1;
}

#endif
