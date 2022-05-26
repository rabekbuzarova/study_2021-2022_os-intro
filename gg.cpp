#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;

class Vector{
    
private:
    int dim;
    double *v;
    int number;
    
//    friend Vector operator+(Vector &vect1, Vector &vect2);
    friend Vector vec_sum(Vector &vect1, Vector &vect2);
    friend class Matrix;
    
public:
    static int count;
    
    Vector(int d, double *var);
    Vector(int d);
    ~Vector();
    
    Vector operator+(Vector &vect2);
    
    int get_dim();
    void set_dim(int d);
    
    void print();
};


int Vector::count = 0;

// constructor (int)
Vector::Vector(int d){
    count++;
    number = count;
    
    cout << "Constructor Vector(int) made vector #"<< number << endl;
    dim = d;
    
    v = new double[dim];
    
    for (int i=0; i<dim; ++i){
        v[i] = 0;
    }
}

Vector::Vector(const Vector& vect2){
    count++;
    number=count;
    dim=vect2.dim;
    v=vect.v;
}

//constructor (int, double)
Vector::Vector(int d, double *var){
    count++;
    number = count;
    
    cout << "Constructor Vector(int, double*) made vector #"<< number << endl;
    dim = d;
    
    v = new double[dim];
    
    for (int i=0; i<dim; ++i){
        v[i]=var[i];
    }
}

// destructor
Vector::~Vector(){
    cout << "Destructor of vector #"<< number << endl;
    delete[] v;
}

// print vector
void Vector::print(){
    cout << "Vector #"<<number<< "(";
    for (int i=0; i<dim-1; ++i){
        cout << v[i] << ", ";
    }
    cout << v[dim-1] << ")" << endl;
}

// method-operator "+"
Vector Vector::operator+(Vector &vect2){
    cout << "Summing Vector #" << number << " with vector #" << vect2.number << endl;
    Vector tmp(dim);
    for (int i=0;i<tmp.dim; ++i){
        tmp.v[i] = v[i] + vect2.v[i];
    }
    int d;
    if (vect2.dim !=dim){
        cout<<"Error"<<endl;
        exit(0);
    }
    return tmp;
}
//-
Vector Vector::operator-(Vector &vect2){
    cout << "Subtracing Vector #" << number << " with vector #" << vect2.number << endl;
    Vector tmp(dim);
    for (int i=0;i<tmp.dim){
        tmp.v[i] = v[i] - vect2.v[i];
    }
     int d;
    if (vect2.dim !=dim){
        cout<<"Error"<<endl;
        exit(0);
    }
    return tmp;
}
//присваивание
Vector Vector::operator=(Vector &vect2){
    cout << "Assign Vector #" << number << " with vector #" << vect2.number << endl;
    delete [];
    this -> dim=vect2.dim;
    v=new double[dim];
    for (int i=0;i<tmp.dim){
        this -> v[i]=vect2.v[i];
    return *this;
}
//уно
Vector Vector::operator-(){
    cout<<"Make Vector# negativity" << number<<endl;
    for (int i=0; i<this->dim; i++){
        v[i]=-v[i];
    }
    return *this;
}

class Matrix
{
    int dim;
    double **b;
    friend Matrix& operator*(double c,Matrix& m);
public:
    static int countmatr;
    int number;
    Matrix(int d);
    Matrix(int d, double **x);
    
//    ~Matrix();
    
    void print()const;
    Matrix operator+(const Matrix &m);//сумма матриц
    Matrix& operator-(const Matrix &m);//разность матриц
    Matrix& operator-();//-матрица
    Matrix operator*(const Matrix &m) const;//произведение матриц
    Matrix& operator=(const Matrix &m);//присваивание (матр)
    Matrix& operator*(double c);//умножение на число
    void antimatr() const;//диагональ
    Vector operator*(const Vector& v) const;//умножение на вектор
};


int Matrix::countmatr=0;

Matrix::Matrix(int d)
{
    countmatr++;
    number=countmatr;
    dim=d;
    
    b=new double *[dim];
    for(int i=0;i<dim;i++)
    {
        b[i]=new double[dim];
    }
    
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            b[i][j]=0;
    
    cout << endl << "Constructor matr(int) made new matrix #"<< number << endl<<endl;
}

Matrix::Matrix(int d,double **x)
{
    countmatr++;
    number=countmatr;
    dim=d;
    
    b=new double*[dim];
    for(int i=0;i<dim;i++)
        b[i]=new double[dim];
    
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            b[i][j]=x[i][j];
    
    cout << endl << "Constructor matr(int, double**) made new matrix #"<< number << endl<<endl;
}

Matrix Matrix::operator+(const Matrix &m)//сумма матриц
{
    cout<<"summing matrix #"<<number<<" with matrix #"<<m.number<<endl;
    Matrix tmp(dim);
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            tmp.b[i][j]=b[i][j]+m.b[i][j];
    return tmp;
}

void Matrix::print() const
{
    cout<<"matrix #"<<number<<endl;
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void exception_example(int a){
    
    int d = 5;
    double *array = new double[d]{1,2,3,4,5};
    Vector v1(d, array);
    
    if (a==0) throw "Some error happens";
    else throw -1;
    
//    std::cout << "This will not be printed" << std::endl;
}

int main(int argc, const char * argv[]) {
    
    // пример обработки исключений
    try {
        exception_example(0);
        std::cout << "code in try block" << std::endl;
    }
    catch(const char *exception) {
        std::cout<< "do something with exception #1:"<< exception <<std::endl;
    }
    catch(int exception){
        std::cout << "do something with exception #2: "<< exception<<std::endl;
    }
    std::cout<<std::endl;
    
    
    
    int d = 5;
    double *array = new double[d]{1,2,3,4,5};
    double *array2 = new double[d]{2,2,2,2,2};

    
    Vector a(d, array);
    Vector b(d, array2);
   
    a.print();
    b.print();
    
    Vector c = a + b;
    
    c.print();
    
    double **matr_array1 = new double *[3]{
        new double[3]{1,2,3},
        new double[3]{4,5,6},
        new double[3]{7,8,9}
    };
    
    double **matr_array2 = new double *[3]{
        new double[3]{1,1,1},
        new double[3]{1,1,1},
        new double[3]{1,1,1}
    };
    
    Matrix m1(3, matr_array1);
    Matrix m2(3, matr_array2);
    
    m1.print();
    m2.print();
    
    Matrix m3 = m1 + m2;
    
    m3.print();
    
    return 0;
}