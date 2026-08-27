class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        flag = false;

        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void set(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};


class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];

            if(!node->contains(ch)) {
                node->set(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool searchHelper(Node* node, string& word, int index) {

        
        if(index == word.length()) {
            return node->isEnd();
        }

        char ch = word[index];

        
        if(ch != '.') {

            if(!node->contains(ch)) {
                return false;
            }

            return searchHelper(node->get(ch), word, index + 1);
        }


        for(int i = 0; i < 26; i++) {

            if(node->links[i] != NULL) {

                if(searchHelper(node->links[i], word, index + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};