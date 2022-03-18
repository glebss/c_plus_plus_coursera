#include <iostream>
#include <vector>
#include <stdexcept>



class Matrix {
public:
    Matrix() {
        num_rows_ = 0;
        num_cols_ = 0;
    }
    Matrix (int num_rows, int num_cols) {
        Reset(num_rows, num_cols);
    }

    void Reset(int new_rows, int new_cols) {
        if (new_rows < 0 || new_cols < 0) {
            throw std::out_of_range("");
        }
        if (new_rows == 0 || new_cols == 0) {
            new_rows = 0;
            new_cols = 0;
        }
        mat.assign(new_rows, std::vector<int>(new_cols));
        num_rows_ = new_rows;
        num_cols_ = new_cols;
    }

    int At(int i, int j) const {
        if (i < 0 || i > num_rows_ - 1 || j < 0 || j > num_cols_ - 1) {
            throw std::out_of_range("");
        }
        return mat[i][j];
    }

    int& At(int i, int j) {
        if (i < 0 || i > num_rows_ - 1 || j < 0 || j > num_cols_ - 1) {
            throw std::out_of_range("");
        }
        return mat[i][j];
    }

    int GetNumRows() const { return num_rows_; }
    int GetNumColumns() const { return num_cols_; }

private:
    std::vector< std::vector<int> > mat;
    int num_rows_;
    int num_cols_;

};


std::istream& operator>>(std::istream& input, Matrix& mat) {
    int num_rows, num_cols;
    input >> num_rows >> num_cols;
    if (num_rows == 0 || num_cols == 0) {
        num_rows = 0;
        num_cols = 0;
    }
    mat.Reset(num_rows, num_cols);
    for (int i=0; i<num_rows; ++i) {
        for (int j=0; j<num_cols; ++j) {
            int mat_elem;
            input >> mat_elem;
            mat.At(i, j) = mat_elem;
        }
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Matrix& mat) {
    output << mat.GetNumRows() << " " << mat.GetNumColumns() << std::endl;
    for (int i=0; i < mat.GetNumRows(); ++i) {
        for (int j=0; j < mat.GetNumColumns(); ++j) {
            output << mat.At(i, j);
            if (j != mat.GetNumColumns() - 1) {
                output << " ";
            }
        }
        output << std::endl;
    }
    return output;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()) {
        return false;
    }

    for (int i=0; i<lhs.GetNumRows(); ++i) {
        for (int j=0; j<lhs.GetNumColumns(); ++j) {
            if (lhs.At(i, j) != rhs.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()) {
        throw std::invalid_argument("");
    }

    int num_rows = lhs.GetNumRows();
    int num_cols = lhs.GetNumColumns();

    Matrix res(num_rows, num_cols);
    for (int i=0; i<num_rows; ++i) {
        for (int j=0; j<num_cols; ++j) {
            res.At(i,j) = lhs.At(i,j) + rhs.At(i,j);
        }
    }
    return res;
}


int main() {
    Matrix one;
    Matrix two;
    std::cin >> one >> two;
    std::cout << one + two << std::endl;
    return 0;
}