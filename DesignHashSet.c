typedef struct {
    int *key[101];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet *obj = (MyHashSet *)malloc(sizeof(MyHashSet));
    if (obj == NULL)
        return NULL;
    for (int i = 0; i < 101; ++i)
    {
        obj->key[i] = (int *)malloc(sizeof(int) * 10000);
        if (obj->key[i] == NULL)
            return NULL;
        memset(obj->key[i], -1, 10000);        
    }
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (obj == NULL)
        return;
    if (key > 1000000)
        return;
    obj->key[key / 10000][key % 10000] = key;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if (obj == NULL)
        return;
    if (key > 1000000)
        return;
    obj->key[key / 10000][key % 10000] = -1;  
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    if (obj == NULL)
        return false;
    if (key > 1000000)
        return false;
    return obj->key[key / 10000][key % 10000] == key;  
}

void myHashSetFree(MyHashSet* obj) {
    if (obj == NULL)
        return;
    for (int i = 0; i < 101; ++i)
    {
        if (obj->key[i] == NULL)
            return;
        free(obj->key[i]);        
    }
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
