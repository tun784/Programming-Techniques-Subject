//  Buổi 4
//          Bài tập thực hành trên lớp -    Bài 2: Câu 4, 5, 6
//          Bài tập thực hành về nhà -  Bài 3: Câu 12, 13, 14
//                                      Bài 4: Câu 1, 2, 3
//  Buổi 6
//          Bài thực hành trên lớp - Bài 3, bài 5
//          Bài thực hành về nhà - Bài 9, bài 10
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int a[1001][1001];

void inputArray2D(int a[][1001], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void outputArray2D(int a[][1001], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Phần tử max thuộc tam giác trên đường chéo chính
int SumTriangleUnder(int a[][1001], int n)
{
    int max = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }
    }
    return max;
}

// Sắp xếp ma trận tăng dần theo kiểu zigzag(tăng từ trái qua phải và từ trên xuống dưới)
double logbase(double a, double base)
{
    return log(a) / log(base);
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

void selectionSortReverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

void sortRow(int a[][1001], int n)
{
    int i, j;
    int *p = new int[n];
    for (i = 0; i < n; i++)
    {

        // Săp xếp từ trái sang phải
        if (i % 2 == 0)
        {
            for (j = 0; j < n; j++)
                p[j] = a[i][j];
            selectionSort(p, n);
            for (j = 0; j < n; j++)
                a[i][j] = p[j];
        }
        // Săp xếp từ phải sang trái
        else
        {
            for (j = 0; j < n; j++)
                p[j] = a[i][n - j - 1];
            selectionSort(p, n);
            for (j = 0; j < n; j++)
                a[i][n - j - 1] = p[j];
        }
    }
    delete p;
}

void sortColumn(int a[][1001], int n)
{
    int i, j;
    int *p = new int[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            p[j] = a[j][i];
        selectionSort(p, n);
        for (j = 0; j < n; j++)
            a[j][i] = p[j];
    }
    delete p;
}

void shearSort(int a[][1001], int n)
{
    int k = (int)ceil(logbase(n, 2)), i;
    for (i = 0; i < k; i++)
    {
        sortRow(a, n);
        sortColumn(a, n);
    }
    sortRow(a, n);
}

// Sắp xếp theo đường chéo chính tăng dần từ trên xuống dưới
void sortMainDiagonal(int a[][1001], int n)
{
    int b[1001];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i][i];
    }

    selectionSort(b, n);

    for (int i = 0; i < n; i++)
    {
        a[i][i] = b[i];
    }
}

//  Liệt kê các cột có tổng nhỏ nhất trong ma trận
void PrintColumMin(int a[][1001], int n)
{
    // tim cot co tong cac phan tu lon nhat
    int res = 1e9, cot;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[j][i];
        }
        if (sum < res)
        {
            res = sum;
            cot = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == cot)
            {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Hoan vi 2 hang cua ma tran
void Swap2Row(int a[][1001], int n)
{
    cout << "\n2 hang muon hoan vi: ";
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < n; i++)
    {
        // a[x][i] = a[y][i]
        int temp = a[x - 1][i];
        a[x - 1][i] = a[y - 1][i];
        a[y - 1][i] = temp;
    }
}
// Hoan vi 2 cot cua ma tran
void Swap2Column(int a[][1001], int n)
{
    cout << "\n2 cot muon hoan vi: ";
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < n; i++)
    {
        // a[i][x] = a[i][y]
        int temp = a[i][x - 1];
        a[i][x - 1] = a[i][y - 1];
        a[i][y - 1] = temp;
    }
}

// Sắp xếp đường chéo phụ tăng dần
void sortSubDiagonal(int a[][1001], int n)
{
    int b[1001];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i][n - i - 1];
    }

    selectionSort(b, n);

    for (int i = 0; i < n; i++)
    {
        a[i][n - i - 1] = b[i];
    }
}

// Sắp xếp đường chéo phụ giảm dần
void sortSubDiagonal_2(int a[][1001], int n)
{
    int b[1001];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i][n - i - 1];
    }

    selectionSortReverse(b, n);

    for (int i = 0; i < n; i++)
    {
        a[i][n - i - 1] = b[i];
    }
}

// Sort ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
void sortRows_increse_decrese(int a[][1001], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
            selectionSort(a[i], n);
        if (i % 2 == 0)
            selectionSortReverse(a[i], n);
    }
}

void MTChuyenVi(int a[][1001], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // quét nửa trên đường chéo chính
        {
            swap(a[i][j], a[j][i]);
        }
    }
}

// Sort ma trận sao cho: các cột có chỉ số lẻ thì tăng dần, còn các cột có chỉ số chẵn thì giảm dần
void sortColumns_increse_decrese(int a[][1001], int n)
{
    MTChuyenVi(a, n);
    sortRows_increse_decrese(a, n);
    MTChuyenVi(a, n);
}

// Phần 6: 3, 5, 9, 10
void DelWhitSpace(char c[])
{
    char *token = strtok(c, " ");
    while (token != NULL)
    {
        cout << token << " ";
        token = strtok(NULL, " ");
    }
}

void surName_Name(char c[], char a[][50])
{
    int n = 0; // Đếm số lượng từ trong câu
    char *token = strtok(c, " ");
    while (token != NULL)
    {
        strcpy(a[n], token);
        ++n;
        token = strtok(NULL, " ");
    }
    cout << "\nHo lot: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nTen: ";
    cout << a[n - 1];
}

void InsertWordIndex(char str[], char strInsert[], int vt)
{
    int n = strlen(str);
    int m = strlen(strInsert);
    char temp[100];
    if (vt < 0 || vt > n)
        return;
    if (vt < n)
    {
        strcpy(temp, str + vt);
        strcpy(str + vt, strInsert);
        strcat(str + vt + m, temp);
    }
    cout << str;
}

void DelWord(char c[], char d[])
{
    char *token = strtok(c, " ");
    while (token != NULL)
    {
        if (strcmp(token, d) != 0)
        {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

int main()
{
    // Phần 4
    // int n;
    // cout << "\nNhap so hang va so cot: ";
    // cin >> n;
    // inputArray2D(a, n);
    // cout << SumTriangleUnder(a, n);
    // shearSort(a, n);
    // sortMainDiagonal(a, n);
    // PrintColumMin(a, n);
    // sortSubDiagonal(a, n);
    // sortRows_increse_decrese(a, n);
    // sortColumns_increse_decrese(a, n);
    // cout << endl;
    // outputArray2D(a, n);

    // Phần 6
    // char c[100];
    // char d[100];
    // char a[50][50];
    // fgets(c, sizeof(c), stdin);
    // c[strlen(c) - 1] = '\0';
    // DelWhitSpace(c);
    // surName_Name(c, a);

    // char str[100];
    // char strInsert[100];
    // int vt;
    // fgets(str, sizeof(str), stdin);
    // str[strlen(str) - 1] = '\0';
    // cout << "\nNhap vi tri can chen: ";
    // cin >> vt;
    // cin.ignore();
    // cout << "\nNhap chuoi can chen: ";
    // fgets(strInsert, sizeof(strInsert), stdin);
    // strInsert[strlen(strInsert) - 1] = '\0';
    // InsertWordIndex(str, strInsert, vt);

    return 0;
}