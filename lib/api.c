#include <string.h>

#include "server.h"
#include "api.h"

int meow_get(MeowServer* server, char* key, char* response) {
  char* value = g_hash_table_lookup(server->memory_store, key);

  strcpy(response, value);

  if(value == NULL) {
    return FALSE;
  } else {
    return TRUE;
  }
}

int meow_put(MeowServer* server, char* key, char* value, char* response) {
  return g_hash_table_insert(server->memory_store, key, value);
}

int meow_delete(MeowServer* server, char* key, char* response) {
  return g_hash_table_remove(server->memory_store, key);
}

int meow_exists(MeowServer* server, char* key, char* response) {
  return g_hash_table_contains(server->memory_store, key);
}
