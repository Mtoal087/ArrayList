using namespace std;

template <typename T>
void ArrayList<T>::grow(){
    T* temp = new T[m_max * 2];
    for(int i = 0; i < m_size; i++){
        temp[i] = m_data[i];
    }
    m_max = m_max * 2;
    delete [] m_data;
    m_data = temp;
}

template <typename T>
void ArrayList<T>::shrink(){
    T* temp = new T[m_max / 2];
    for(int i = 0; i < m_size; i++){
        temp[i] = m_data[i];
    }
    m_max = m_max / 2;
    delete [] m_data;
    m_data = temp;
}

template <typename T>
ArrayList<T>::ArrayList(int s, const T& x){
    while(s > m_max){
        grow();
    }
    m_size = s;
    T* temp = new T[m_max];
    for(int i = 0; i < m_size; i++){
        temp[i] = x;
    }
    delete [] m_data;
    m_data = temp;
}

template <typename T>
ArrayList<T>::~ArrayList(){
    m_size = m_max = 0;
    delete [] m_data;
    m_data = NULL;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs){
    delete [] m_data;
    m_data = new T[rhs.m_max];
    m_max = rhs.m_max;
    for(int i = 0; i < rhs.m_max; i++){
        m_data[i] = rhs.m_data[i];
    }
    m_size = rhs.m_size;
    return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy){
    delete [] m_data;
    m_data = NULL;
    m_max = m_size = 0;
    *this = cpy;
}

template <typename T>
int ArrayList<T>::size() const{
    return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const{
    if(m_size != 0)
        return m_data[0];
    else{
        cout << "!!! ERROR : ARRAYLIST.first() !!! (List is empty)\n";
        return m_errobj;
    }
}

template <typename T>
T& ArrayList<T>::operator[](int i){
    if(i >= 0 && i < m_size)
        return m_data[i];
    else{
        cout << "!!! ERROR : ARRAYLIST.[] !!! (index out of bounds)\n";
        return m_errobj;
    }
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const{
    if(i >= 0 && i < m_size)
        return m_data[i];
    else{
        cout << "!!! ERROR : ARRAYLIST.[] !!! (index out of bounds)\n";
        return m_errobj;
    }
}

template <typename T>
int ArrayList<T>::search(const T& x) const{
    for(int i = 0; i < m_size; i++){
        if(m_data[i] == x)
            return i;
    }
    return -1;
}

template <typename T>
void ArrayList<T>::clear(){
    delete [] m_data;
    m_size = 0;
    m_max = 4;
    m_data = new T[m_max];
}

template <typename T>
void ArrayList<T>::insert_back(const T& x){
    m_size++;
    if(m_size > m_max)
        grow();
    m_data[m_size - 1] = x;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i){
    m_size++;
    if(m_size > m_max)
        grow();
    if(i > m_max){
        cout << "!!! ERROR : ARRAYLIST.insert() !!! (index out of bounds)\n";
        m_size--;
        return;
    }
    else{
        for(int k = m_size; k > i; k--){
            m_data[k] = m_data[k-1];
        }
        m_data[i] = x;
    }
}

template <typename T>
void ArrayList<T>::remove(int i){
    if(i < 0 || i > m_max){
        cout << "!!! ERROR : ARRAYLIST.remove() !!! (index out of bounds)\n";
        return;
    }
    else{
        for(int k = i; k < m_size; k++){
            m_data[k] = m_data[k+1];
        }
        m_size--;
        if((m_size < m_max/4) && (m_max > 4)){
            shrink();
        }
    }
}

template <typename T>
void ArrayList<T>::swap(int i, int k){
    if(i < 0 || i > m_size || k < 0 || k > m_size){
        cout << "!!! ERROR : ARRAYLIST.swap() !!! (index out of bounds)\n";
        return;
    } else{
        T tmp = m_data[i];
        m_data[i] = m_data[k];
        m_data[k] = tmp;
    }
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist){
    int num = size() + alist.size();
    while(num > m_max){
        grow();
    }
    for(int i = 0; i < alist.size(); i++){
        insert_back(alist.m_data[i]);
    }
    m_size = num;
}

template <typename T>
void ArrayList<T>::reverse(){
    T* temp = new T[m_max];
    int j = 0;
    for(int i = m_size - 1; i >= 0; i--){
        temp[j] = m_data[i];
        j++;
    }
    delete [] m_data;
    m_data = temp;
}