#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  struct hash *hashTable = NULL;
  int eleCount = 0;
  struct node {
        long long int phno;
        int key;
        char name[100];
        struct node *next;
  };
  struct hash {
        struct node *head;
        int count;
  };
  struct node * createNode(int key,char *name,long long int phno) {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->key = key;
        newnode->phno = phno;
        strcpy(newnode->name, name);
        newnode->next = NULL;
        return newnode;
  }
  void insertToHash(char *name,long long int phno) {
      int key=name[0];
        int hashIndex = key % eleCount;
        struct node *newnode =  createNode(key ,name, phno);
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                return;
        }
        newnode->next = (hashTable[hashIndex].head);
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
        return;
  }
  void deleteFromHash(char *name) {
      int key=name[0];
        int hashIndex = key % eleCount, flag = 0;
        struct node *temp, *myNode;
        myNode = hashTable[hashIndex].head;
        if (!myNode) {
                printf("Given data is not present in hash Table!!\n");
                return;
        }
        temp = myNode;
        while (myNode != NULL) {
                if (strcmp(myNode->name,name)==0) {
                        flag = 1;
                        if (myNode == hashTable[hashIndex].head)
                                hashTable[hashIndex].head = myNode->next;
                        else
                                temp->next = myNode->next;
                        hashTable[hashIndex].count--;
                        free(myNode);
                        break;
                }
                temp = myNode;
                myNode = myNode->next;
        }
        if (flag)
                printf("Data deleted successfully from Hash Table\n");
        else
                printf("Given data is not present in hash Table!!!!\n");
        return;
  }
void searchInHash(char *name) {
      int key=name[0],i,c=0;
        int hashIndex = key % eleCount, flag = 0;
        struct node *myNode;
        myNode = hashTable[hashIndex].head;
        if (!myNode) {
                printf("Search element unavailable in hash table\n");
                return;
        }
        while (myNode != NULL) {
      if(strcmp(myNode->name,name)==0){
        printf("Name     : %s\n", myNode->name);
                printf("phno      : %lld\n", myNode->phno);
                flag = 1;
                break;
      }
      myNode = myNode->next;
        }
        if (!flag)
                printf("Search element unavailable in hash table\n");
        return;
  }  
  void display() {
        struct node *myNode;
        int i;
        for (i = 0; i < eleCount; i++) {
                if (hashTable[i].count == 0)
                        continue;
                myNode = hashTable[i].head;
                if (!myNode)
                        continue;
                while (myNode != NULL) {
                        printf("%-15s", myNode->name);
                        printf("%lld\n", myNode->phno);
                        myNode = myNode->next;
                }
        }
        return;
  }
int main() {
        int n=10, ch;
        long long int phno;
        char name[100];
        eleCount = n;
        hashTable = (struct hash *)calloc(n, sizeof (struct hash));
        printf("------------------------------------MINI TELEPHONE DIRECTORY PROJECT--------------------------------------------------\n");
      printf("      \n");
      printf("                                           Team Members\n");
      printf("                 \n");
        printf("                                 1. 2110030011- M Nagendra Prasad\n");
      printf("                                 2. 2110030102- C Sri charan\n");
      printf("       \n");
      printf("----------------------------------------------------------------------------------------------------------------------");
        while (1) {
          printf("                                 \n");
                      printf("\n1.Insert a number in the Telephone Directory\n");
    printf("2.Delete a number from Telephone Directory\n");
    printf("3.Search in the Telephone Directory\n");
    printf("4.Display all the numbers in Telephone Directory\n");
    printf("5. Exit \n");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                getchar();
                                printf("Name:");
                                fgets(name, 100, stdin);
                                name[strlen(name) - 1] = '\0';
                                printf("phno:");
                                scanf("%lld", &phno);
                                while(phno<1000000000 || phno>=10000000000){
                                  printf("Error!!\nEnter correct phno (10 Digits : )");
                  scanf("%lld",&phno);
                }
                                insertToHash(name, phno);
                                break;
                        case 2:
                                printf("Enter the name to perform deletion:");
                                scanf("%s", name);
                                deleteFromHash(name);
                                break;
case 3:
                                printf("Enter the name to search:");
                                scanf("%s", name);
                                searchInHash(name);
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("You have entered wrong option!!\n");
                                break;
                }
        }
        return 0;
  }

