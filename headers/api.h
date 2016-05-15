#ifndef API_H_   /* Include guard */
#define API_H_

int meow_get(char* key, char* response);

int meow_put(char* key, char* value, char* response);

int meow_delete(char* key, char* response);

int meow_exists(char* key, char* response);

#endif // API_H_
