#ifndef API_H_   /* Include guard */
#define API_H_

int meow_get(MeowServer* meow, char* key, char* response);

int meow_put(MeowServer* meow, char* key, char* value, char* response);

int meow_delete(MeowServer* meow, char* key, char* response);

int meow_exists(MeowServer* meow, char* key, char* response);

#endif // API_H_
