#include <iostream>
#include <string>
using namespace std;

class Matrix
{
private:
    double **_arrayRow;
    int _sizeRow;
    int _sizeCol;

public:
    Matrix(int sizeRow, int sizeCol)
    {
        _sizeCol = sizeCol;
        _sizeRow = sizeRow;

        _arrayRow = new double *[_sizeRow];

        for (int i = 0; i < _sizeRow; i++)
        {
            _arrayRow[i] = new double[_sizeCol];
            for (int k = 0; k < _sizeCol; k++)
            {
                _arrayRow[i][k] = 0.0;
            }
        }
    }

    Matrix(int sizeRow, int sizeCol, double **copyArray)
    {
        _sizeCol = sizeCol;
        _sizeRow = sizeRow;

        _arrayRow = new double *[_sizeRow];

        for (int i = 0; i < _sizeRow; i++)
        {
            _arrayRow[i] = new double[_sizeCol];
            for (int k = 0; k < _sizeCol; k++)
            {
                _arrayRow[i][k] = copyArray[i][k];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < _sizeRow; i++)
        {
            delete[] _arrayRow[i]; // Free each row
        }
        delete[] _arrayRow; // Free the row pointer array
    }

    int rowLength()
    {
        return _sizeRow;
    }

    int colLength()
    {
        return _sizeCol;
    }

    double getVal(int i, int j)
    {
        return _arrayRow[i][j];
    }

    void setValue(int row, int col, double val)
    {
        _arrayRow[row][col] = val;
    }

    Matrix matrix_multiply(Matrix& matrix)
    {
        Matrix multi(_sizeRow, matrix.colLength());
        for (int i = 0; i < multi.rowLength(); i++)
        {
            for (int j = 0; j < multi.colLength(); j++)
            {
                double val = 0.0;
                for (int k = 0; k < _sizeCol; k++)
                {
                    val = val + _arrayRow[i][k] * matrix.getVal(k, j);
                }
                multi.setValue(i, j, val);
            }
        }
        return multi;
    }

    Matrix operator+(Matrix &matrix){
        Matrix addition(_sizeRow, _sizeCol);
        for(int i = 0;i<_sizeRow;i++){
            for(int k = 0;k< _sizeCol;k++){
                addition.setValue(i,k, _arrayRow[i][k] + matrix.getVal(i,k));
            }
        }
        return addition;
    }

    Matrix operator-(Matrix &matrix){
        Matrix minus(_sizeRow, _sizeCol);
        for(int i = 0;i<_sizeRow;i++){
            for(int k = 0;k< _sizeCol;k++){
                minus.setValue(i,k, _arrayRow[i][k] - matrix.getVal(i,k));
            }
        }
        return minus;
    }

    friend ostream &operator<<(ostream &out, const Matrix &matrix)
    {
        for (int i = 0; i < matrix._sizeRow; i++)
        {
            out << "[";
            for (int j = 0; j < matrix._sizeCol; j++)
            {
                out << '\t' << matrix._arrayRow[i][j];
            }
            out << "]\n";
        }
        return out;
    }
};

int main()
{

    int row1 = 3;
    int col1 = 4;

    int row2 = 4;
    int col2 = 1;

    double **array1 = new double *[row1];

    for (int i = 0; i < row1; i++)
    {
        array1[i] = new double[col1];
        for (int j = 0; j < col1; j++)
        {
            array1[i][j] = i * 10 + j;
        }
    }

    double **array2 = new double *[row2];

    for (int i = 0; i < row2; i++)
    {
        array2[i] = new double[col2];
        for (int j = 0; j < col2; j++)
        {
            array2[i][j] = i * 10 + j;
        }
    }

    Matrix matrix1(row1, col1, array1);

    Matrix matrix2(row2, col2, array2);

    Matrix multiplication = matrix1.matrix_multiply(matrix2);

    Matrix addition = matrix2 + matrix2;
    Matrix subt = matrix2 - matrix2;

    cout << matrix1 << endl;
    cout << matrix2 << endl;

    cout<< multiplication << endl;
    cout<< addition  << endl;
    cout << subt  << endl;

    for (int i = 0; i < row1; i++) {
        delete[] array1[i];
    }
    delete[] array1;

    for (int i = 0; i < row2; i++) {
        delete[] array2[i];
    }
    delete[] array2;

    return 0;
}