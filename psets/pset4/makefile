Node* remove(Node* head, int key) {
    node* pre = head, 
    node* zap = head->next;
    while(zap->data!= key) {	
      pre = zap;
      zap = zap->next;
    }
    pre->next = zap->next;
    delete zap;
    return head;
}
