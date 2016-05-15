#ifndef API_H_   /* Include guard */
#define API_H_

int zen_get(ZenServer* server, char* key, char* response);

int zen_put(ZenServer* server, char* key, char* value, char* response);

int zen_delete(ZenServer* server, char* key, char* response);

int zen_exists(ZenServer* server, char* key, char* response);

#endif // API_H_
