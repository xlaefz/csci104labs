

template <typename T>
LList<T>::LList() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

template <typename T>
LList<T>::LList(const LList& other) {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
  Item<T>* temp = other.head_;
  while(temp){
    push_back(temp->val);
    temp = temp->next;
  }
}

template <typename T>
LList<T>& LList::operator=(const LList& other) {
  if(this == &other){
    return *this;
  }
  clear();
  Item<T>* temp = other.head_;
  while(temp){
    push_back(temp->val);
    temp = temp->next;
  }
  return *this;
}

LList<T>::~LList() {
  clear();
}

int LList<T>::size() const {
  return size_;
}

template <typename T>
bool LList<T>::empty() const {
  return size_ == 0;
}

template <typename T>
void LList<T>::push_back(T& val) {
  if(head_ == NULL){
    head_ = new Item<T>;
    head_->val = val;
    head_->next = NULL;
    head_->prev = NULL;
    tail_ = head_;
    size_ = 1;
  }
  else {
    Item<T>* n = new Item<T>;
    n->val = val;
    n->next = NULL;
    n->prev = tail_;
    tail_->next = n;
    tail_ = n;
    size_++;
  }
}

T& LList<T>::get(int loc) {
  Item<T> *temp = getNodeAt(loc);
  return temp->val;
}

T const & LList<T>::get(int loc) const {
  Item<T> *temp = getNodeAt(loc);
  return temp->val;
}

void LList<T>::clear() {
  while(head_ != NULL) {
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

T* LList<T>::getNodeAt(int loc) const {
  Item<T> *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}


