#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

#define Alphabet_Size 26

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define Char_to_Index(c) (int )c-(int)'a'

struct TrieNode
{
    struct TrieNode *children[Alphabet_Size] ;

    bool isLeaf ;

};

struct TrieNode* createnode()
{
    struct TrieNode* newnode = (struct TrieNode*)malloc(sizeof(TrieNode));
    if (newnode==NULL){
        cout<<"Memory error"<<endl;
        return 0;
        }
    else
    {
        int i ;
        for(i=0;i<Alphabet_Size;i++)
            newnode->children[i] = NULL ;
        newnode->isLeaf =true;


    }
    return newnode ;
};

void insert(struct TrieNode*root, char *key)
{
    int len = strlen(key);
    int i = 0;
    int c ;
    for(i=0;i<len;i++)
    {
         c = Char_to_Index(key[i]);
        if(!root->children[c])
            root->children[c]=createnode();
        root = root->children[c];
    }
    root->isLeaf=true;
}

bool search(struct TrieNode*root, char *key)
{
int len = strlen(key);
int i ;
struct TrieNode *crawler =root;
for(i=0;i<len;i++)
{
    int c = Char_to_Index(key[i]);
    if(!crawler->children[c])
        return false;

    crawler = crawler->children[c];

}
return(crawler->isLeaf&&crawler!=NULL);

}

int main()
{
    char keys[][10] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their","thaw"};

    char output[][32] = {"Not present in trie", "Present in trie"};


    struct TrieNode *root = createnode();

    // Construct trie
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);

    // Search for different keys
    cout<<"the"<< output[search(root, "the")]<<endl;
   cout<<"these"<< output[search(root, "these")]<<endl;
   cout<<"their"<< output[search(root, "their")]<<endl ;
   cout<<"thaw"<< output[search(root, "thaw")]<<endl ;

    return 0;

}
