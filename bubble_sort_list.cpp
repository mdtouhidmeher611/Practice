void bubblesort(Node* head){
	if(head==nullptr) return;

	Node* current;
	bool swapped;
	Node* lastnode=nullptr;

	do{
		swapped = false;
		current = head;
		while(current->next != lastnode){
			if(current->data>current->next->data){
				int temp = current->data;
				current->data = current->next->data;
				current->next->data=temp;
				swapped=true;
			}
			current=current->next;
		}
		lastnode=current;

	}while(swapped)

}