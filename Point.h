#ifndef TP7_POINT_H
#define TP7_POINT_H

//Testtttt
template<class T> class Point {
private:
    T m_x;
    T m_y;
public:
    Point(T,T);
    Point(Point<T> const& autre);
    void setX(T);
    void setY(T);
    void print();
    T getX();
    T getY();
};


#endif //TP7_POINT_H

template<class T> Point<T>::Point(T x, T y) : m_x(x), m_y(y){}
template<class T> Point<T>::Point(const Point<T> &autre) : m_x(autre.getX()), m_y(autre.getY()) {}

template<class T> void Point<T>::setX(T x) {
    m_x=x;
}

template<class T> void Point<T>::setY(T y) {
    m_y=y;
}

template<class T> T Point<T>::getX() {
    return m_x;
}

template<class T> T Point<T>::getY() {
    return m_y;
}

template<class T> void Point<T>::print() {
    std::cout << "Point(T,T) : " << this << std::endl;
    std::cout << "(" << m_x << "," << m_y << ")" << std::endl;
    std::cout << "~Point : " << this << std::endl;

}