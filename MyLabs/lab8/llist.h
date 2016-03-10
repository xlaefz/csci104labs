// TODO(1): Copy the contents of llist.cpp here, below the class definition

// TODO(2): Template the item
template <typename T>
struct Item {
  T val;
  Item<T> *prev;
  Item<T> *next;
};


// TODO(3): Template the class, as well as all the functions inside it
// Change all mentions of int to the templated type name
template <typename T>
class LList {
 public:
  LList<T>();
  LList<T>(const LList& other);
  LList<T>& operator=(const LList& other);
  ~LList<T>();

  // TODO(5): Change the signatures of these methods appropriately
  int size() const;
  bool empty() const;
  void push_back(T val);
  T& get(int pos);
  T const & get(int pos) const;
  void clear();

 private:
  Item<T>* getNodeAt(int pos);
  
  // TODO(4): What types should these data members me?
  Item<T>* head_;
  Item<T>* tail_;
  int size_;
};



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
LList<T>& LList<T>::operator=(const LList& other) {
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

template <typename T>
LList<T>::~LList() {
  clear();
}

template <typename T>
int LList<T>::size() const {
  return size_;
}

template <typename T>
bool LList<T>::empty() const {
  return size_ == 0;
}

template <typename T>
void LList<T>::push_back(T val) {
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

template <typename T>
T& LList<T>::get(int loc) {
  Item<T> *temp = getNodeAt(loc);
  return temp->val;
}

template <typename T>
T const & LList<T>::get(int loc) const {
  Item<T> *temp = getNodeAt(loc);
  return temp->val;
}

template <typename T>
void LList<T>::clear() {
  while(head_ != NULL) {
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

template <typename T>
Item<T>* LList<T>::getNodeAt(int loc) {
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


