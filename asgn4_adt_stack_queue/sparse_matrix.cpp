#include <iostream>
using namespace std;


template <class T>
class SparseMatrix{
    private:
        class Pair{
            public:
                int r;
                int c;
                T value;
                Pair(int r, int c, T value){
                    this->r = r;
                    this->c = c;
                    this->value = value;
                }
        };
        Pair **array;
        int row;
        int col;
        int size;
    public:
        SparseMatrix(int row = 1, int col = 1){
            if(row<1||col<1){
                throw std::runtime_error("Need both row and col at least size 1 long");
            }
            this->row = row;
            this->col = col;
            array = new Pair *[row*col];
            for(int i = 0;i<row*col;i++){
                array[i] = nullptr;
            }
            size = 0;
        }
        ~SparseMatrix(){
            for(int i = 0;i< row*col;i++){
                if(array[i]){
                    delete array[i];
                }
            }

            delete[] array;
        }
        int getRow() const {
            return row;
        }
        int getCol() const {
            return col;
        }
        int getSize() const {
            return size;
        }
        
        T getElement(int _row, int _col){
            for(int i = 0;i< row*col;i++){
                if(array[i] && array[i]->r == _row && array[i]->c ==_col){
                    return array[i]->value;
                }
            }
            return 0;
        }
        Pair* getElement(int index){
            if(index>=row*col){
                throw std::runtime_error("Out of bounds!");
            }
            return array[index];
        }
        void insertElement(const int _row, const int _col, const T& value){
            for(int i = 0;i< row*col;i++){
                if(array[i] && array[i]->r == _row && array[i]->c ==_col){
                    array[i]->value = value;
                    return;
                }
            }
            if(size>=row*col){
                return;
            }
            Pair *pair = new Pair(_row, _col, value);
            array[size]  = pair;
            size++;
        }

        void deleteElement(int _row, int _col){
            for(int i = 0;i<row*col;i++){
                if(array[i] && array[i]->r == _row && array[i]->c ==_col){
                    delete  array[i];
                    array[i] = nullptr;
                    size--;
                    break;
                }
            }
        }

        SparseMatrix* multiply(SparseMatrix &matrix){
            if(col!=matrix.getRow()){
                throw std::runtime_error("Matrix multiplication mismatch");
            }
            SparseMatrix<T> *mult = new SparseMatrix<T>(row, matrix.getCol());     
            for(int i = 0;i<row*col;i++){
                if(!array[i]){
                    continue;
                }
                for(int j = 0;j<matrix.getRow() * matrix.getCol();j++){
                    if(!matrix.getElement(j)){
                        continue;
                    }

                    if(array[i]->c==matrix.getElement(j)->r){
                        T val = mult->getElement(array[i]->r, matrix.getElement(j)->c)   + (array[i]->value)*(matrix.getElement(j)->value);
                        mult->insertElement(array[i]->r, matrix.getElement(j)->c, val );
                    }
                }
            }
            return mult;
        }

        void display() {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    cout << getElement(i, j) << "\t";
                }
                cout << endl;
            }
        }
        

};

int main() {
    SparseMatrix<int> mat1(3, 2);  
    SparseMatrix<int> mat2(2, 3);  

    
    // mat1.insertElement(0, 0, 1);
    // mat1.insertElement(0, 1, 2);
    // mat1.insertElement(1, 0, 3);
    mat1.insertElement(1, 1, 4);
    // mat1.insertElement(2, 0, 5);
    mat1.insertElement(2, 1, 6);

    // mat2.insertElement(0, 0, 7);
    // mat2.insertElement(0, 1, 8);
    // mat2.insertElement(0, 2, 9);
    // mat2.insertElement(1, 0, 10);
    mat2.insertElement(1, 1, 11);
    mat2.insertElement(1, 2, 12);
    cout << "Matrix 1:" << endl;
    mat1.display();

    cout << "Matrix 2:" << endl;
    mat2.display();

    SparseMatrix<int>* result = mat1.multiply(mat2);
    cout << "Multiplication Result:" << endl;
    result->display();

    delete result;
    return 0;
}
