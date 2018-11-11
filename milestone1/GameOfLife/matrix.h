#ifndef MATRIX_H
#define MATRIX_H
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Matrix
{
    typedef std::vector<double> Vector;

public:
    size_t getRows() const;
    size_t getCols() const;
    double getElement(size_t, size_t) const;
    void createString();
    void setElement(size_t, size_t, double);

    Matrix();
    Matrix(size_t, size_t);
    Matrix(const Matrix &);
    Matrix(const char *);
    ~Matrix() = default;

private:
    std::vector<Vector> data;
    void initilizer(size_t, size_t);
    string old_matrix;
    string new_matrix;

protected:
    size_t rows;
    size_t cols;
};

#endif // MATRIX_H
