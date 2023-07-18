class Node
{
    public:
    Node*next;Node*prev;int val;
    int key;
    Node(int val,int key)
    {
        this->key=key;
        next=NULL;
        prev=NULL;
        this->val=val;
    }
};
class LRUCache {
public:
    Node*head,*tail;
    map<int,Node*>mp;
    int msize=0;
    LRUCache(int capacity) 
    {
        head=NULL;
        tail=NULL;
        msize=capacity;    
    }
    int get(int key) 
    {
        if (!mp.count(key))
        {
            return -1;
        }    
        upgrade(key,mp[key]->val);
        return mp[key]->val;
    }
    
    void put(int key, int value) 
    {
        if (!mp.count(key))
        {
            add(key,value);
        }    
        else
        {
            upgrade(key,value);
        }
    }
    void add(int key,int value)
    {
        Node*temp=new Node(value,key);
        if (head==NULL)
        {
            head=temp;
            tail=head;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        mp[key]=head;
        checkPop();
    }
    void upgrade(int key,int value)
    {
        Node*temp=mp[key];
        temp->val=value;
        if (temp==head)
        {
            return ;
        }
        else if (temp==tail)
        {
            Node*tailTemp=tail->prev;
            temp->prev->next=NULL;
            temp->prev=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
            tail=tailTemp;
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            temp->next=head;
            head->prev=temp;
            temp->prev=NULL;
            head=temp;
        }
    }
    void checkPop()
    {
        if(mp.size()>msize)
        {
            mp.erase(tail->key);
            Node*temp=tail->prev;
            tail->prev=NULL;
            delete tail;
            tail=temp;
        }
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
