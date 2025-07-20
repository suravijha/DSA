// LeetCode 146
/* Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity. */

class Node
{
public:
    int val;
    int key;
    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:
    int cap;
    unordered_map<int, Node *> cache;
    Node *left;
    Node *right;

    void remove(Node *node)
    {
        Node *before = node->prev;
        Node *after = node->next;
        before->next = after;
        after->prev = before;
    }

    void insert(Node *node)
    {
        Node *before = right->prev;
        before->next = node;
        node->prev = before;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
            remove(cache[key]);

        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap)
        {
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */