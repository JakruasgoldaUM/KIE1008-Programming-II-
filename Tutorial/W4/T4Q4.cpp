#include <iostream>
using namespace std;

class matrixType
{
  private:
    int rows, columns;
    int **matrix; // Pointer to a 2D array
   public:
    matrixType(int r, int c)
    {
        rows = r;
        columns = c;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new int[columns];
    }
    void input ()
    {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                cin >> matrix[i][j];
    }
    void display ()
    {
        cout << "The matrix is:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
    ~matrixType()
    {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    matrixType operator+(const matrixType &other)
    {
        if (rows != other.rows || columns != other.columns)
        {
            cout << "Matrix dimensions do not match for addition." << endl;
            exit(1);
        }

        matrixType result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];

        return result;
    }

    matrixType (const matrixType &other)
    {
        rows = other.rows;
        columns = other.columns;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[columns];
            for (int j = 0; j < columns; j++)
                matrix[i][j] = other.matrix[i][j];
        }
    }

    matrixType operator*(const matrixType &other)
    {
        if (columns != other.rows)
        {
            cout << "Matrix dimensions do not match for multiplication." << endl;
            exit(1);
        }

        matrixType result(rows, other.columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.columns; j++)
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < columns; k++)
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }

        return result;
    }
};

int main()
{
    int r, c;
    matrixType A(2,2), B(2,2);
    cout << "Matrix A: " << endl;
    A.input();

    cout << "Matrix B: " << endl;
    B.input();

    matrixType C = A + B;
    matrixType D = A * B;
    cout << "For A + B:" << endl;
    C.display();
    cout << "For A * B:" << endl;
    D.display();

    return 0;
}