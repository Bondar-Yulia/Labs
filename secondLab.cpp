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
        cout << "�������������� ������� ����������(n1!=n2 or m1!=m2)";
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
        cout << "��������� ������ ���������� (n1 != m2)";
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

int main() {
    setlocale(LC_ALL, "");
    unsigned int n1, m1, size1, n2, m2, size2, i1, j;
    vector<MatrixElement> matrix1, matrix2, res1, res2;
    int x;
    cout << "������� ������� 1-�� �������:";
    cin >> n1 >> m1;
    size1 = n1 * m1;
    if (size1 < 20) {
        cout << "� ������ ������� ��� ���������, ������� �� ����� 1(���������<20,��� �� ��������� ��������� �������)";
    }
    else {
        for (unsigned int i = 0; i < (n1 * m1) / 20; ++i) {
            cout << "������� ����� ������, ������� � �������� " << i << "-�� ��������, �� ������� 1:";
            cin >> i1 >> j >> x;
            matrix1.push_back(MatrixElement(i1, j, x));
        }
    }
    cout << "������� ������� 2-�� �������:";
    cin >> n2 >> m2;
    size2 = n2 * m2;
    if (size2 < 20) {
        cout << "�� ������ ������� ��� ���������, ������� �� ����� 1(���������<20,��� �� ��������� ��������� �������)";
    }
    else {
        for (unsigned int i = 0; i < (n2 * m2) / 20; ++i) {
            cout << "������� ����� ������, ������� � �������� " << i + 1 << "-�� ��������, �� ������� 1:";
            cin >> i1 >> j >> x;
            matrix2.push_back(MatrixElement(i1, j, x));
        }
    }
    if (size1 < 20 and size2 < 20) {
        cout << "� ������ ������� ��� ������";
        return 0;
    }
    else {
        bool ismatch = false;
        Matrixsum(n1, m1, n2, m2, matrix1, matrix2, res1);
        if (!res1.empty()) {
            cout << "�������, ������������ � ���������� �����";
            for (unsigned int i = 0; i < n1; ++i) {
                for (unsigned int j = 0; j < m1; ++j) {
                    ismatch = false;
                    for (unsigned int z = 0; z < res1.size(); ++z) {
                        if (i == res1[z].row and j == res1[z].column) {
                            cout << res1[z].value << " ";
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
    return 0;
}