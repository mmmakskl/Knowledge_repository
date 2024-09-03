#include"Structs.h"
 Stack::~Stack()
 {
	 if (top)
	 {
		 NodeStack* previous = top;
		 NodeStack* ptr = top->next_;
		 while (ptr)
		 {
			 delete previous;
			 previous = ptr;
			 ptr = ptr->next_;
		 }
		 delete previous;
	 }
 }

 bool Stack::isEmpty() const { return !top ? true : false; }

 void Stack::push(AVL_Tree::Node* key)
 {
	 NodeStack* new_el = new NodeStack(key);
	 if (!top) top = new_el;
	 else
	 {
		 NodeStack* ptr = top;
		 while (ptr->next_) ptr = ptr->next_;
		 ptr->next_ = new_el;
	 }
 }

 AVL_Tree::Node* Stack::getTop() const
 {
	 if (top)
	 {
		 NodeStack* ptr = top;
		 while (ptr->next_) ptr = ptr->next_;
		 return ptr->key_;
	 }
	 else throw std::runtime_error(ERROR_STACK_UNDERFLOW);
 }

 void Stack::pop()
 {
	 if (top)
	 {
		 NodeStack* previous = top;
		 if (previous->next_)
		 {
			 NodeStack* ptr = top->next_;
			 while (ptr->next_)
			 {
				 previous = previous->next_;
				 ptr = ptr->next_;
			 }
			 previous->next_ = nullptr;
			 delete ptr;
		 }
		 else
		 {
			 top = nullptr;
			 delete previous;
		 }

	 }
	 else throw std::runtime_error(ERROR_STACK_UNDERFLOW);
 }
