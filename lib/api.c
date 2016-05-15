#include <string.h>
#include <stdio.h>

#include "server.h"
#include "api.h"

void list(ZenServer* server) {
  GList* keys = g_hash_table_get_keys(server->memory_store);
  GList* l;

  for (l = keys; l != NULL; l = l->next) {
    printf("key: %s\n", (char*)l->data);

    char* value = g_hash_table_lookup(server->memory_store, l->data);

    printf("value: %s\n", (char*)value);
  }
}

int zen_get(ZenServer* server, char* key, char* response) {
  list(server);

  char* value = g_hash_table_lookup(server->memory_store, key);

  printf("lookup: %s\n", value);

  if(value == NULL) {
    return FALSE;
  } else {
    strcpy(response, value);

    return TRUE;
  }
}

int zen_put(ZenServer* server, char* key, char* value, char* response) {
  int result = g_hash_table_insert(server->memory_store, strdup(key), strdup(value));

  list(server);

  return result;
}

int zen_delete(ZenServer* server, char* key, char* response) {
  list(server);

  return g_hash_table_remove(server->memory_store, key);
}

int zen_exists(ZenServer* server, char* key, char* response) {
  list(server);

  return g_hash_table_contains(server->memory_store, key);
}
