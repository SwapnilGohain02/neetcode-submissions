class LRUCache {
public:

    class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    unordered_map<int,Node*> mp;

    Node* head;
    Node* tail;

    int capacity;

    LRUCache(int cap) {

        capacity = cap;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node){

        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node* node){

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mp.find(key) != mp.end()){

            Node* node = mp[key];

            deleteNode(node);

            node->value = value;

            addNode(node);

            return;
        }

        // Cache full
        if(mp.size() == capacity){

            Node* lru = tail->prev;

            deleteNode(lru);

            mp.erase(lru->key);

            delete lru;
        }

        Node* newNode = new Node(key,value);

        addNode(newNode);

        mp[key] = newNode;
    }
};