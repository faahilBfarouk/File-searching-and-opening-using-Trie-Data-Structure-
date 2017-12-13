#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include<string.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


int val;
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];


    bool isLeaf;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}


void insert_C(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }


    pCrawl->isLeaf = true;
}
void insert_F(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }


    pCrawl->isLeaf = true;
}


bool search_C(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isLeaf);
}
int search_F(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return val=0;

        pCrawl = pCrawl->children[index];
    }

     if((pCrawl != NULL && pCrawl->isLeaf))
        return val=1;

}
void search_again()
{
    int n;
    printf("enter 1 to search again or 0 to exit:");
    scanf("%d",&n);
    if(n==1)
    main();
    else
    {
        printf("Program Terminates!");
        exit(0);
    }
}


int main()
{

    char keys_F[13][20] = {"animals","all","elephant","giraffe","panda","tiger","tortoise","monuments",
                           "wonders","funny","cartoon"};
    char keys_C[13][20]={"birds","hen","ostrich","all","parrot","pigeon","scientists",
                            "apj","einstein","galileo","quotes"};

    char output[2][40] = {"Not present in database", "Present in database"};


    struct TrieNode *root = getNode();
        struct TrieNode *root_f = getNode();

    int i;
    for (i = 0; i < ARRAY_SIZE(keys_C); i++)
        insert_C(root, keys_C[i]);

    for (i = 0; i < ARRAY_SIZE(keys_F); i++)
          insert_F(root_f, keys_F[i]);

char f[100],h[100],t[10],g[200]="explorer ";
printf("Type Of File(image or video):");
scanf("%s",t);
strlwr(t);
printf("Keyword 1:");
scanf("%s",f);
strlwr(f);
if(search_F(root_f,f))

   {
    strcat(g,"F:\\");
    printf("Keyword 1 present in F drive\n");
   }
else if(search_C(root,f))
    {
    strcat(g,"C:\\");
    printf("Keyword 1 present in C drive\n");
    }
else
{
    printf("Keyword 1 not present in C or F drive\n");
    search_again();
}
printf("keyword 2:");
scanf("%s",h);
strlwr(h);
strcat(g,f);

    if(!search_C(root,h))
    {

       if(!search_F(root_f,h))
        {
            printf("Keyword 2 not present in C or F drive\n");
            search_again();
        }

    }

    if(strcmp(h,"all")==0&&search_C(root,f))

       {
           printf("%s.......%s\n",f, output[search_C(root,f)] );
           system(g);
           search_again();
       }

    if(strcmp(h,"all")==0&&search_F(root_f,f))
       {
           printf("%s.......%s\n",f, output[search_F(root_f,f)] );
           system(g);
           search_again();
       }

    strcat(g,"\\");

    char k[5]=".jpg";
    char kt[5]=".mp4";

    if(strcmp(t,"video")==0)
        {
            strcat(g,"video\\");


            strcat(g,h);
            strcat(g,kt);


        }

    else if(strcmp(t,"image")==0)
        {
            strcat(g,h);
            strcat(g,k);
        }
    else
    {
        printf("type unrecognizable please try again\n");
        search_again();
    }
    if(search_C(root,h))
        printf("%s >> %s.......%s\n",f,h, output[search_C(root,f)] );
    if(search_F(root_f,h))
        printf("%s >> %s.......%s\n",f,h, output[search_F(root_f,f)] );

    system(g);
    search_again();



}
