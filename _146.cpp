struct node{
    node* before;
    node* after;
    int val;
    int key;
    node(int val, int key){
        this->val = val;
        this->key = key;
    }
    void set(int val){
        this->val = val;
    }
};
class LRUCache{
    
private:
    int size;
    map<int,node*> m;
    node* head;
    node* tail;
public:
    LRUCache(int capacity) {
        size = capacity;
        head = new node(0,0);
        tail = new node(0,0);
        head->after = tail;
        tail->before = head;
        
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        else{
            node* now = m[key];
            now->before->after = now->after;
            now->after->before = now->before;
            
            node* next = head->after;
            
            now->before = head;
            head->after = now;
            
            now->after = next;
            next->before = now;
            
            return now->val;
            
        }
    }
    
    void set(int key, int value) {
        int target = get(key);
        if(target == -1){
            node* newOne = new node(value,key);
            head->after->before = newOne;
            newOne->after = head->after;
            head->after = newOne;
            newOne->before = head;
            m[key] = newOne;
            if(m.size() == size+1){
                node* last = tail->before;
                last->before->after = tail;
                tail->before = last->before;
                m.erase(last->key);
                delete last;
            }
            
        }
        else{
            if(value != head->after->val){
                head->after->set(value);
            } 
        }
    }
};
