#include "definitions.h"
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

char addLine(Node *table, Node *line)
{
  if(table == NULL) return __ERROR__;

  line->next = table->next;
  table->next = line;

  return __OK__;
}

char removeLine(Node *table, unsigned int ipAddress)
{
  Node *prev;
  prev = searchLine(table, ipAddress);
  if(prev != NULL)
  {
    Node *n = prev->next;
    prev->next = n->next;
    free(n);
    return __OK__;
  }

  return __ERROR__;
}

Node* searchLine(Node *table, unsigned int ipAddress)
{
  Node *n = table;
  while(n->next != NULL)
  {
    if((n->next)->ipAddress == ipAddress)
      return n;
  }
  return NULL;
}

void printLine(Node *line, unsigned int lineId)
{
  printf("%10d | ", lineId);

  unsigned int ip = line->ipAddress;
  printf("%3u.%3u.%3u.%3u | ", (ip & 0xFF000000)>>24, (ip & 0x00FF0000) >> 16,
                            (ip & 0x0000FF00) >> 8, ip & 0x000000FF);

  unsigned char *mac = line->macAddress;
  printf("%2X:%2X:%2X:%2X:%2X:%2X | ", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

  printf("%3d\n", line->ttl);
}

void printTable(Node *table)
{
  printf("  Entrada  |   Endereço IP   | Endereço Ethernet | TTL\n");
  Node *n = table->next;

  unsigned int i = 0;
  while(n != NULL)
  {
    printLine(n, i);
    n = n->next;
    i++;
  }
}

Node* newLine(unsigned int ipAddress, unsigned char *macAddress, short int ttl)
{
  Node *node = (Node*) malloc(sizeof(Node));
  node->ipAddress = ipAddress;

  for(unsigned int i = 0; i < 6; i++)
  {
    node->macAddress[i] = macAddress[i];
  }

  node->ttl = ttl;
  node->next = NULL;

  return node;
}

// int main()
// {
//   unsigned char macAddress[6] = {62, 92, 63, 93, 64, 94};
//   Node* l0 = newLine(0, macAddress, 64);
//   Node table;
//   table.next = NULL;
//   addLine(&table, l0);
//   printTable(&table);
//   removeLine(&table, 0);
//   printTable(&table);
//   return 0;
// }
