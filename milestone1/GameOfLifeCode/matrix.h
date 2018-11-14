#ifndef MATRIX_H
#define MATRIX_H
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class matrix
    //creates the class matrix
{
public:
    typedef std::vector<double> Vector;

public:
    size_t getRows() const;
    size_t getCols() const;
    double getElement(size_t, size_t) const;
    void createString();
    matrix importData(string source);
    void exportData(string source);
    matrix evolution();
    void setElement(size_t, size_t, double);

    matrix();
    matrix(size_t, size_t);
    matrix(const matrix &);
    matrix(const char *);
    ~matrix() = default;

private:
    std::vector<Vector> data;
    void initilizer(size_t, size_t);
    string str_matrix;

protected:
    size_t rows;
    size_t cols;
};

#endif // MATRIX_H
