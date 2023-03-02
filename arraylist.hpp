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
    T* temp;
    temp = new T[m_max / 2];
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
    T* temp;
    temp = new T[m_max];
    for(int i = 0; i < m_size; i++){
        temp[i] = x;
    }
    m_data = temp;
}

template <typename T>
ArrayList<T>::~ArrayList(){
    delete [] m_data;
    m_data = NULL;
    m_size = 0;
    m_max = 0;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs){
    delete [] m_data;
	m_data = new T[rhs.m_max];
    m_max = rhs.m_max;
    for(int i = 0; i < rhs.m_size; i++){
		m_data[i] = rhs.m_data[i];
	}
    m_size = rhs.m_size;
	return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy){
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
    return m_data[0];
}

template <typename T>
T& ArrayList<T>::operator[](int i){
    if(i >= 0 && i < m_size)
        return m_data[i];
    else{
        cout << "!Error!" << endl;
        return m_errobj;
    }
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const{
    if(i >= 0 && i < m_size)
        return m_data[i];
    else{
        cout << "!Error!" << endl;
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
    for(int k = m_size; k > i; k--){
        m_data[k] = m_data[k-1];
    }
    m_data[i] = x;
}

template <typename T>
void ArrayList<T>::remove(int i){
    if(i < 0)
        return;
    for(int k = i; k < m_size; k++){
        m_data[k] = m_data[k+1];
    }
    m_size--;
    if((m_size < m_max/4) && (m_max > 4)){
        shrink();
    }
}

template <typename T>
void ArrayList<T>::swap(int i, int k){
    T tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist){
    
}

template <typename T>
void ArrayList<T>::reverse(){
    
}

