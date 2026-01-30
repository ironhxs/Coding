// 设计链表
// 关键点: 双向链表+虚拟头节点，统一增删操作
// 易错点: 1.边界检查index范围 2.双向链表需维护prev指针 3.注意next可能为空
// 日期: 2026.01.30

class MyLinkedList {
public:

    struct MyLinkedListNode{
        int val;
        MyLinkedListNode *prev;
        MyLinkedListNode *next;
        MyLinkedListNode(int val=0):val(val),prev(nullptr),next(nullptr){
        }
    };
    
    MyLinkedList(){
        _dummy_head = new MyLinkedListNode();
        _dummy_head->prev = _dummy_head;
        _dummy_head->next = _dummy_head;
        _size = 0;
    }
    
    int get(int index) {
        if(index > _size - 1 || index < 0)
            return -1;
        MyLinkedListNode *temp = _dummy_head;
        for(int i = 0;i <= index;i ++)
            temp = temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        MyLinkedListNode * new_code = new MyLinkedListNode(val);
        new_code -> prev = _dummy_head;
        new_code -> next = _dummy_head -> next;
        _dummy_head -> next = new_code;
        //后面有可能为空
        if(new_code -> next)
            new_code -> next->prev = new_code;
        _size ++;
    }
    
    void addAtTail(int val) {
        MyLinkedListNode *temp = _dummy_head;
        for(int i = 0;i <= _size - 1;i++)
            temp = temp->next;
        MyLinkedListNode * new_code = new MyLinkedListNode(val);
        new_code -> prev = temp;
        temp -> next = new_code;
        _size ++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size||index < 0)
            return;
        if(index ==_size){
            addAtTail(val);
            return;
        }
        MyLinkedListNode *temp = _dummy_head;
        for(int i = 0;i <= index - 1;i ++)
            temp = temp->next;
        MyLinkedListNode * new_code = new MyLinkedListNode(val);
        new_code->prev = temp;
        new_code->next = temp->next;
        temp->next = new_code;
        if(new_code->next)
            new_code->next->prev = new_code;
        _size ++;
    }
    
    void deleteAtIndex(int index) {
        if(index > _size - 1||index < 0)
            return;
        MyLinkedListNode *temp = _dummy_head;
        for(int i = 0;i <= index - 1;i++)
            temp = temp->next;
        MyLinkedListNode *delete_node = temp->next;
        temp->next = delete_node->next;
        if(delete_node->next)
            delete_node->next->prev = temp;
        delete delete_node;
        _size --;
    }
    private:
        MyLinkedListNode *_dummy_head;
        int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
