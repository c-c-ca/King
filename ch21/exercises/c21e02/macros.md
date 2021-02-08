## MinGW\include\assert.h

```
_CRTIMP void _cdecl __MINGW_NOTHROW _assert (const char*, const char*, int) _MINGW_ATTRIB_NORETURN;

...

#define assert(e)      ((e) ? (void)0 : _assert(#e, __FILE__, __LINE__))

```
