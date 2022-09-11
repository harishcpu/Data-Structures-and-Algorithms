template<typename T>
class Vector{
    //Data Member
    T *arr;
    int currentSize;
    int maxSize;

    //Constructor, Destructor
public:
    Vector(int max_size=1) {
        currentSize = 0;
        maxSize = max_size;
        arr = new T[maxSize];
    }

    void push_back(int d) {
        //Two cases
        if(currentSize == maxSize) {
            //create new array of double capacity
            //delete the old one after copying elements
            T *oldArr = arr;
            maxSize = 2*maxSize;
            arr = new T[maxSize];

            //copy the elements
            for(int i=0; i<currentSize; i++) {
                arr[i] = oldArr[i];
            }

            //delete old arr
            delete [] oldArr;
        }
        arr[currentSize] = d;
        ++currentSize;
    }

    void pop_back() {
        if(currentSize >= 0) {
            --currentSize;
        }
    }

    bool isEmpty() const{
        return currentSize==0;
    }

    //front, back, ar[i], []
    T front() const{
        return arr[0];
    }

    T back() const{
        return arr[currentSize-1];
    }

    T at(int i) const{
        return arr[i];
    }

    int size() const{
        return currentSize;
    }

    int capacity() const {
        return maxSize;
    }

    T operator[](const int i) const{
        return arr[i];
    }
};
