#include <string.h>

#include "server.h"
#include "api.h"

int zen_get(ZenServer* server, char* key, char* response) {
  char* value = g_hash_table_lookup(server->memory_store, key);

  strcpy(response, value);

  if(value == NULL) {
    return FALSE;
  } else {
    return TRUE;
  }
}

int zen_put(ZenServer* server, char* key, char* value, char* response) {
  return g_hash_table_insert(server->memory_store, key, value);
}

int zen_delete(ZenServer* server, char* key, char* response) {
  return g_hash_table_remove(server->memory_store, key);
}

int zen_exists(ZenServer* server, char* key, char* response) {
  return g_hash_table_contains(server->memory_store, key);
}
