
typedef struct {
    int key[100];
    int val[100];
} MyPair;

typedef struct {
    MyPair *pair[10001];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap *map = (MyHashMap *)malloc(sizeof(MyHashMap));
    if (map != NULL)
    {
        for (int i = 0; i < 10001; ++i)
        {
            map->pair[i] = (MyPair *)malloc(sizeof(MyPair));
            if (map->pair[i] != NULL)
            {
                for (int j = 0; j < 100; ++j)
                {
                    map->pair[i]->key[j] = -1;
                    map->pair[i]->val[j] = -1;
                }                
            }            
        }
    }
    return map;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int val) {
    if (obj == NULL)
    {
        return;
    }
    if (key > 1000000)
        return;
    if (obj->pair[key / 100] == NULL)
        return;
    if (val > 1000000)
        return;
    obj->pair[key / 100]->key[key % 100] = key;
    obj->pair[key / 100]->val[key % 100] = val;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    if (obj == NULL)
        return -1;
    if (key > 1000000)
        return -1;
    if (obj->pair[key / 100] == NULL)
        return -1;
    return obj->pair[key / 100]->val[key % 100];
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    if (obj == NULL)
        return -1;
    if (key > 1000000)
        return -1;
    if (obj->pair[key / 100] == NULL)
        return -1;
    obj->pair[key / 100]->key[key % 100] = -1;
    obj->pair[key / 100]->val[key % 100] = -1;  
}

void myHashMapFree(MyHashMap* obj) {
    if (obj == NULL)
        return;
    for (int i = 0; i < 10001; ++ i)
    {
        if (obj->pair[i] != NULL)
        {
            free(obj->pair[i]);
        }
    }
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
