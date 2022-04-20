#include<iostream>
#include<vector>
using namespace std;

struct MatrixElement {
    MatrixElement(unsigned int r, unsigned int c, int v) :
        row(r), column(c), value(v) {};
    unsigned int row, column;
    int value;
};

void Matrixsum(unsigned int n1, unsigned int m1, unsigned int n2, unsigned int m2, vector<MatrixElement>& a, vector<MatrixElement>& b, vector<MatrixElement>& c) {
    if (n1 != n2 or m1 != m2) {
        cout << "Просуммировать матрицы невозможно(n1!=n2 or m1!=m2)";
        return;
    }
    else {
        vector<MatrixElement> res;
        bool iselem2 = false;
        for (MatrixElement k : a) {
            res.push_back(k);
        }
        for (MatrixElement k : b) {
            iselem2 = false;
            for (unsigned int i = 0; i < res.size(); ++i) {
                if (res[i].row == k.row and res[i].column == k.column) {
                    res[i].value += k.value;
                    iselem2 = true;
                    break;
                }
            }
            if (!iselem2) {
                res.push_back(k);
            }
        }
        c = res;
        return;
    }
}

void MatrixProduct(unsigned int n1, unsigned int m1, unsigned int n2, unsigned int m2, vector<MatrixElement>& a, vector<MatrixElement>& b, vector<MatrixElement>& c) {
    if (n1 != m2) {
        cout << "Умножение матриц невозможно (n1 != m2)";
        return;
    }
    else {
        vector<MatrixElement> res;
        bool iselem2 = false;
        for (MatrixElement k : a) {
            res.push_back(k);
        }
        for (MatrixElement k : b) {
            iselem2 = false;
            for (unsigned int i = 0; i < res.size(); ++i) {
                if (res[i].row == k.row and res[i].column == k.column) {
                    res[i].value *= k.value;
                    iselem2 = true;
                    break;
                }
            }
            if (!iselem2) {
                res.push_back(k);
            }
        }
        c = res;
        return;
    }
}

void enterMatrix(unsigned int n, unsigned int m, unsigned int size, unsigned int j, vector<MatrixElement>& matrix) {
    cout << "Введите размеры матрицы:";
    cin >> n >> m;
    size1 = n * m;
    if (size < 20) {
        cout << "В матрице нет елементов, которые не равны 1(елементов<20,что не позволяет выполнить условие)";
    }
    else {
        for (unsigned int i = 0; i < (n1 * m1) / 20; ++i) {
            cout << "Введите номер строки, столбца и значение " << i << "-го елемента, не равного 1:";
            cin >> i >> j >> x;
            matrix.push_back(MatrixElement(i, j, x));
        }
    }
    return;
}

void displayMatrixsSum(unsigned int size1, unsigned int size2, unsigned int n1, unsigned int m1, unsigned int n2, unsigned int m2, vector<MatrixElement>& matrix1, vector<MatrixElement>& matrix2, vector<MatrixElement>& res) {
    if (size1 < 20 and size2 < 20) {
        cout << "В поиске решения нет смысла";
        return 0;
    }
    else {
        bool ismatch = false;
        Matrixsum(n1, m1, n2, m2, matrix1, matrix2, res);
        if (!res.empty()) {
            cout << "Матрица, получившаяся в результате суммы";
            for (unsigned int i = 0; i < n1; ++i) {
                for (unsigned int j = 0; j < m1; ++j) {
                    ismatch = false;
                    for (unsigned int z = 0; z < res.size(); ++z) {
                        if (i == res[z].row and j == res[z].column) {
                            cout << res[z].value << " ";
                            ismatch = true;
                        }
                    }
                    if (!ismatch) {
                        cout << 2 << " ";
                        if (j == m1 - 1) cout << endl;
                    }
                }
            }
        }
    }
    return;
}

void displayMatrixsProduct(unsigned int size1, unsigned int size2, unsigned int n1, unsigned int m1, unsigned int n2, unsigned int m2, vector<MatrixElement>& matrix1, vector<MatrixElement>& matrix2, vector<MatrixElement>& res) {
    if (size1 < 20 and size2 < 20) {
        cout << "В поиске решения нет смысла";
        return 0;
    }
    else {
        bool ismatch = false;
        Matrixsum(n1, m1, n2, m2, matrix1, matrix2, res);
        if (!res.empty()) {
            cout << "Матрица, получившаяся в результате умножения";
            for (unsigned int i = 0; i < n1; ++i) {
                for (unsigned int j = 0; j < m1; ++j) {
                    ismatch = false;
                    for (unsigned int z = 0; z < res.size(); ++z) {
                        if (i == res[z].row and j == res[z].column) {
                            cout << res[z].value << " ";
                            ismatch = true;
                        }
                    }
                    if (!ismatch) {
                        cout << 2 << " ";
                        if (j == m1 - 1) cout << endl;
                    }
                }
            }
        }
    }
    return;
}

int main() {
    setlocale(LC_ALL, "");
    unsigned int n1, m1, size1, n2, m2, size2, i1, j;
    vector<MatrixElement> matrix1, matrix2, res1, res2;
    enterMatrix(n1, m1, size1, j, matrix1);
    enterMatrix(n2, m2, size2, j, matrix2);
    displayMatrixsSum(size1, size2, n1, m1, n2, m2, matrix1, matrix2, res1);
    displayMatrixsProduct(size1, size2, n1, m1, n2, m2, matrix1, matrix2, res2);
    return 0;
}